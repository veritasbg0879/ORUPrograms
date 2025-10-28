#include "global.h"
#include "javaclass.h"
#include "bytecode.h"

#define MAX_SIZE 127

struct ClassFile cf;
int index1, index2, index3;
int label1, label2;

int tk; // lookahead token
int stackDepth;

int retLoc[2*MAX_SIZE];
int numRets = 0;

extern int assign_var_index(int tokenval);
extern int match(int token); 
extern void stmt();
extern void opt_stmts();
extern void expr();
extern void term();
extern void moreterms();
extern void factor();
extern void morefactors();

//*******************************************************************************

void
java_preamble() {
    // set up new class file structure
    init_ClassFile(&cf);

    // class has public access
    cf.access = ACC_PUBLIC;

    // class name is "Code"
    cf.name = "Code";

    // no fields
    cf.field_count = 0;

    // one method
    cf.method_count = 1;

    // allocate array of methods (just one "main" in our example)
    cf.methods = (struct MethodInfo*)malloc(cf.method_count * sizeof(struct MethodInfo));

    // method has public access and is static
    cf.methods[0].access = ACC_PUBLIC | ACC_STATIC;

    // method name is "main"
    cf.methods[0].name = "main";

    // method descriptor of "void main(String[] arg)"
    cf.methods[0].descriptor = "([Ljava/lang/String;)V";

    // max operand stack size of this method
    cf.methods[0].max_stack = MAX_SIZE;

    // the number of local variables in the local variable array
    //   local variable 0 contains "arg"
    //   local variable 1 contains "val"
    //   local variable 2 contains "i" and "result"
    cf.methods[0].max_locals = 3 + MAX_SIZE;

    // set up new bytecode buffer
    init_code();
    
    // generate code
/*LOC*/
/*000*/	emit(aload_0);
/*001*/	emit(arraylength);		// arg.length
/*002*/	emit2(newarray, T_INT);
/*004*/	emit(astore_1);			// val = new int[arg.length]
/*005*/	emit(iconst_0);
/*006*/	emit(istore_2);			// i = 0
    label1 = pc;			// label1:
/*007*/	emit(iload_2);
/*008*/	emit(aload_0);
/*009*/	emit(arraylength);
    label2 = pc;
/*010*/	emit3(if_icmpge, PAD);		// if i >= arg.length then goto label2
/*013*/	emit(aload_1);
/*014*/	emit(iload_2);
/*015*/	emit(aload_0);
/*016*/	emit(iload_2);
/*017*/	emit(aaload);			// push arg[i] parameter for parseInt
    index1 = constant_pool_add_Methodref(&cf, "java/lang/Integer", "parseInt", "(Ljava/lang/String;)I");
/*018*/	emit3(invokestatic, index1);	// invoke Integer.parseInt(arg[i])
/*021*/	emit(iastore);			// val[i] = Integer.parseInt(arg[i])
/*022*/	emit32(iinc, 2, 1);		// i++
/*025*/	emit3(goto_, label1 - pc);	// goto label1
    backpatch(label2, pc - label2);	// label2:

}

//*******************************************************************************

void
java_postamble() {

    for (int i = 0; i < numRets; i++) {
		backpatch(retLoc[i], pc - retLoc[i]);
    }
    index2 = constant_pool_add_Fieldref(&cf, "java/lang/System", "out", "Ljava/io/PrintStream;");
/*036*/	emit3(getstatic, index2);	// get static field System.out of type PrintStream
/*039*/	emit(iload_2);			// push parameter for println()
    index3 = constant_pool_add_Methodref(&cf, "java/io/PrintStream", "println", "(I)V");
/*040*/	emit3(invokevirtual, index3);	// invoke System.out.println(result)
/*043*/	emit(return_);			// return

    // length of bytecode is in the emmiter's pc variable
    cf.methods[0].code_length = pc;
    
    // must copy code to make it persistent
    cf.methods[0].code = copy_code();

    // save class file to "Code.class"
    save_classFile(&cf);
}

//*******************************************************************************

int
match(int token) {
    int rc = 0;  // in case we don't have a match, we return "false"

    if (token == tk) {
		rc = 1;
		tk = lexan(); // get next token
    }

    return(rc);
}

//*******************************************************************************

void 
stmt() {
    int var_index;
    int loc = -1;
    int if_loc = -1;
    int else_loc = -1;

    // switch based on current token
    switch (tk) {
	/* if token is a left curly brace, match and parse stmts inside braces
    if there is a not a right/closing curly to match, give an error and break */
    case LEFT_CURLY:
        match(LEFT_CURLY);
        opt_stmts();
        if (!match(RIGHT_CURLY)) {
        	error("Expected closing curly brace");
        }
        break;
	
case ID:
		// creating a var_index that is set to the location of the tokenval
	    var_index = symtable[tokenval].var_index;
		
		// if var_index negative, return an error
	    if (var_index < 0) {
			error("Attempting to use keyword as variable");
	    } else if (var_index == 0) {
			var_index = assign_var_index(tokenval); // initializing variable
	    }
	    // else case already taken care of, just overwrite existing variable
	    
		// find match of ID
	    match(ID);
		// if there is not a match to EQ, return an error
	    if (!match(EQ)) {			
			error("Expected assignment operator");
	    }
	    expr();

		// if the stackDepth is >= 1
	    if (stackDepth >= 1) {
			// adding var_index to stack
			emit2(istore, var_index);
			stackDepth--;
	    } else { // if stackDepth is 0, return an error
			error("No rvalue for assignment operator");
	    }
		// if there's not a token ";"
	    if (!match(';')) {
			//return an error
			error("Expected ';'");
	    }
		// done witth the ID case
	    break;
	
	case IF:
		//  Match the key word IF and move to the next token
	    match(IF);

		/* Match the left parenthesis that is required in the
		   syntax of an if statement and if it isn't found throw
		   error */

	    if (!match('(')) {
			error("Missing parenthesis");
	    }

		// call expr function because if statement requires 
		// a boolean expression
	    expr();

		/* Match the right parenthesis that is required in the
		   syntax of an if statement and if it isn't found throw
		   error */
	    if (!match(')')) {
			error("Missing parenthesis");
	    }

		// push a 0 onto the stack
	    emit(iconst_0);
		// set the if_loc variable to the current program counter
	    if_loc = pc;
		// use the java bytecode to see if the ints are equal
	    emit3(if_icmpeq, 0);

		// call statement function to take in next token
	    stmt();

		// set the else_loc variable to current program counter
		else_loc = pc;
		// use the java bytecode to jump to else statement
		emit3(goto_,else_loc);
		// backpatch the value of if_loc because we set the label without 
		// the proper number
		backpatch(if_loc, pc - if_loc);	

		
		// if there is an else statement to the previously found if
		if (match(ELSE)) {
			// call the statement function
			stmt();
			// use java code to jump to location of else
			emit3(goto_,else_loc - pc);
			// backpatch the value of else_loc because we set the label without 
			// the proper number
			backpatch(else_loc, pc - else_loc);
		}
	
	    break;
	
	case WHILE:
		//  match the string 'while' in the given text
	    match(WHILE);

		// if the program doesn't match the token '(' throw an error to the
		// user to let them know they're missing a left parenthesis
	    if (!match('(')) {
			error("Missing left parenthesis");
	    }
		
		// save the value of the pc under the lable test_loc
	    int test_loc = pc;
		
		// match an expression recursively
	    expr();

		// if the right parenthesis isn't matched let the user know
	    if (!match(')')) {
			error("Missing right parenthesis");
	    }
		
		// push 0 onto the stack
	    emit(iconst_0);
		// set the loc equal to the program counter value at this point
	    loc = pc;
		// compare the values 
	    emit3(if_icmpeq, 0);

		// call recursive statement matcher
	    stmt();

		// hop back by subtracting the current program counter value from the 
		// test_loc value. the value is now negative so the pc goes back
	    emit3(goto_, test_loc-pc);
		
		// set the loc value to the value of the program counter 
	    backpatch(loc, pc-loc);
	    break;
	
	case RET:
        //match ret token and parse the expression
        match(RET);
        expr();
        /* if there is a value on the stack, store at location 2, and keep track 
        of where the return was */
        if (stackDepth >= 1) {
            emit(istore_2);
            retLoc[numRets] = pc;
            /* will emit a goto to have the program goto the return location,
            and update the number of return location in case of multiple returns */
            emit3(goto_, retLoc[numRets]);
            numRets++;
        } else {
            error("No value to return, stack empty");
        }
        /* will check to see if there is a semicolon to end the statement 
        and if not produce an error */
        if (!match(';')) {
            error("Missing semicolon");
        }
	}
}

//*******************************************************************************

void
opt_stmts() {
	// if the current token is not a close parentthesis then we call statements
	// and again optional statements because there could be an infinite number
	// of statements back to back
	if(tk != '}'){
		stmt();
	}
	if(tk != '}'){
		opt_stmts();
	}

}

//*******************************************************************************

void
expr() {
	// calls term and more terms as defined by the grammar
    term();
	moreterms();
}

//*******************************************************************************

void
term() {
	// calls factor and morefactors as defined by the grammar
    factor();
	morefactors();	
}

//*******************************************************************************

void
moreterms() {
	// if the current token is not ; or )
    if (!(tk==';' || tk==')')) {
		// switch statement based on the value of the current token
		switch (tk) {
			/* If the token is '+' then call match, then call term as defined in 
			* the grammar. If there is not at least 2 items in the stack throw 
			* an error because addition cannot be performed on 1 operand
			*/
			case PLUS:
				match(PLUS);
				term();
				if (stackDepth < 2) {
					error("Not enough operands for '+'");
				}
				// use the bytecode function for integer addition
				emit(iadd);
				// subtract one from stackDepth because two is popped and the sum
				// is pushed
				stackDepth--;

				// call more terms as defined by the grammar
				moreterms();
				break;
			
			case MINUS:
				/* If the token is '-' then call match, then call term as defined in 
				* the grammar. If there is not at least 2 items in the stack throw 
				* an error because addition cannot be performed on 1 operand
				*/
				match(MINUS);
				term();
				if (stackDepth < 2) {
					error("Not enough operands for '-'");
				}
				// use the bytecode function for integer subtraction
				emit(isub);
				// subtract one from stackDepth because two is popped and the differnce
				// is pushed
				stackDepth--;
				// call more terms as defined by the grammar
				moreterms();
				break;

			case EPSILON:
				// epsilon is matched becasue it is part of the grammar
				// for moreterms and nothing else happens
				match('&');
				break;
				
			default:
				// if no recognized token is passed throw error
				error("Expected '+' or '-'");

				
		}
	}
}

//*******************************************************************************

void
morefactors() {
	// if the token is not +, -, ;, or )
    if (!(tk=='+' || tk=='-' || tk==';' || tk==')')) {
		switch (tk) {
			/* If the token is '*' then call match, then call factor as defined in 
				* the grammar. If there is not at least 2 items in the stack throw 
				* an error because addition cannot be performed on 1 operand
			*/
			case MUL:
				match(MUL);
				factor();
				if (stackDepth < 2) {
					error("Not enough operands for '*'");
				}
				// use the bytecode function for integer multiplication
				emit(imul);
				// subtract one from stackDepth because two is popped and the product
				// is pushed
				stackDepth--;
				// call more factors as defined in the grammar
				morefactors();
				break;
	    
	    case FSLASH:
			/* If the token is '/' then call match, then call factor as defined in 
				* the grammar. If there is not at least 2 items in the stack throw 
				* an error because addition cannot be performed on 1 operand
			*/
			match(FSLASH);
			factor();
			if (stackDepth < 2) {
				error("Not enough operands for '/'");
			}
			// use the bytecode function for integer division
			emit(idiv);
			// subtract one from stackDepth because two is popped and the quotient
			// is pushed
			stackDepth--;
			// call more factors as defined in the grammar
			morefactors();
			break;		
		
		case MOD:
			/* If the token is '%' then call match, then call factor as defined in 
				* the grammar. If there is not at least 2 items in the stack throw 
				* an error because addition cannot be performed on 1 operand
			*/
			match(MOD);
			factor();
			if (stackDepth < 2) {
				error("Not enough operands for '%'");
			}
			// use the bytecode function for integer modulation
			emit(irem);
			// subtract one from stackDepth because two is popped and the remainder
			// is pushed
			stackDepth--;
			// call more factors as defined in the grammar
			morefactors();
			break;	

		case EPSILON:
			// epsilon is matched becasue it is part of the grammar
			// for moreterms and nothing else happens
			match('&');
			break;	

	    default:
			// if no recognized token is passed throw error
			error("Expected '*', '/' or '%'");

	
	}
    }
}

//*******************************************************************************

void
factor() {
    // set the integer var_index to -1
    int var_index = -1;


    // create a switch statement based on what the token is 
    switch (tk) {


    // create a case where the token is the '('
    case LEFT_PAREN:
        // match the '(' character
        match('(');
        // call the recursive expr function 
        expr();
        // if the program doesn't match the ')' throw an error
        if (!match(')')) {
        	error("Missing close parenthesis");
        }
        break;
    
    // make a case if the token is a '-' character
    case MINUS:
        // match the '-' character
        match('-');
        // make sure there's an operand to negate using the stackDepth val.
        // if not throw an error
        if (stackDepth < 1) {
        	error("Not enough operands for negation");
        }
        // call the factor function recursively
        factor();
        // tell the jvm we have a negative int
        emit(ineg);
        break;
    
    // case if tk is an int8!
    case INT8:
        // push the int8 onto the stack - bipush is pushing the data type,
        // tokenval is the numerical value
        emit2(bipush, tokenval);
        // increment stackdepth
        stackDepth++;


        // match the int
        match(INT8);
        break;
    
    // case for tk = int16
    case INT16:
        // similar to above - push int16 onto stack, sipush is 
        // pushing a data type and token val is the val being pushed
        emit3(sipush, tokenval);
        // increment stackdepth
        stackDepth++;


        // match the int16
        match(INT16);
        break;
    
    // make a case for tk = int32
    case INT32:
        // push the int on the stack
        emit2(ldc, constant_pool_add_Integer(&cf, tokenval));
        // increment stackdepth
        stackDepth++;


        // match the int 32
        match(INT32);
        break;
    
    // case when recieved token is 'id'
    case ID:
        // the value at var_index is set to the var_index value at the 
        // tokenval index of the symtable array
        var_index = symtable[tokenval].var_index;
        // if the value is less than zero then it's not valid, throw error
        if (var_index < 0) {
        	error("Keywords are not valid lvalues");
        	// but also if the value equals 0 then it's not real, throw error
        } else if (var_index == 0) {
        	error("Variable does not exist");
        	// otherwise load the var_index value and increment stackdepth
        } else {
            emit2(iload, var_index);
            stackDepth++;
        }


        // match the ID!
        match(ID);
        break;
    
    // a case when recieved token is 'arg' 
    case ARG:
        // match arg!
        match(ARG);
        // push the address of the arg array onto the stack by pushing the value
        // at [1] of our local variables array
        emit(aload_1);
        // if the left bracket isn't matched throw an error
        if (!match('[')) {
            error("Missing left bracket");  
        }
        // push an int8 onto the stack where the value is tokenval
        emit2(bipush,tokenval);
        // if the number isn't matched throw an error
        if(!match(INT8)) {
            error("Missing integer");
        }


        // if the right bracket isn't matched throw an error
        if (!match(']')) {
            error("Missing right bracket");
        }
        // put the integer at the correct index of our arg array
        emit(iaload);
        // increment stack depth
        stackDepth++;
        break;


    // default case when none of the cases are matched
    default:
        // throw an error. a case should always be matched and if it's not
        // there's a problem.
        error("Expected a factor");
        break;
    }
}


//*******************************************************************************

int main() {

	// initializing symbol table
    init();

	// sets everything up for java to initialize set variables
    java_preamble();

	// gets token and sets to tk
    tk = lexan();

	// if the token doesn't say DONE or EOF...
    if (!(tk == DONE || tk == EOF)) {
		// call statement to find keyword since file isn't empty
		stmt();
    }

	// saves java processing
    java_postamble();

    // Useful to do the following when debugging
    //dumpSumbolTable();

    return 0;
}
