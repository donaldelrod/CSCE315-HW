grammar pa2;


WS 
	: ('\t' | '\r' | '\n' | ' ')+ -> skip ; 

fragment ALPHA
	: ('a' .. 'z') | ('A' .. 'Z') | '_' ;

DIGIT
	: ('0' ..'9') ;
	
SELECT 
	: 'SELECT' | 'select' ;

PROJECT
	: 'PROJECT' | 'project';
	
RENAME
	: 'RENAME' | 'rename';

PLUS
	: '+' ;

MINUS
	: '-' ;

PRODUCT
	: '*' ;
	
EQUAL
	: '=' ;
	
LARROW
	: '<-' ;
	
COMMA
	: ',' ;
	
SEMICOLON
	: ';' ;
	
DOUBLEAND
	: '&&' ;
	
DOUBLEOR
	: '||' ;
	
OPEN
	: 'OPEN' ;

CLOSE
	: 'CLOSE' ;

WRITE
	: 'WRITE' ;

EXIT
	: 'EXIT' ;
	
SHOW
	: 'SHOW' ;

CREATE
	: 'CREATE' ;

TABLE
	: 'TABLE' ;

PRIMARY
	: 'PRIMARY' ;

FOREIGN
	: 'FOREIGN' ;

KEY
	: 'KEY' ;

UPDATE
	: 'UPDATE' ;

SET
	: 'SET' ;

WHERE
	: 'WHERE' ;
	
INTEGER
	: 'INTEGER' ;

VARCHAR
	: 'VARCHAR' ;

/*CHAR
	: 'CHAR' ;
	
DATET
	: 'DATE' ;
	
TIMET
	: 'TIME' ;
*/
RELATION
	: 'RELATION' ;
	
INSERT
	: 'INSERT' ;

INTO
	: 'INTO' ;

DELETE
	: 'DELETE' ;
	
VALUES
	: 'VALUES' ;

FROM
	: 'FROM' ;
	
LPAR
	: '(' ;
	
RPAR
	: ')' ;
	
OPERATION
	: '==' | '!=' | '>' | '<' | '<=' | '>=';

LITERAL
	: '"' IDENTIFIER '"' ;
	
IDENTIFIER
	: ALPHA (ALPHA | DIGIT)* ;

integer
	: DIGIT+ ;
	
type
	: INTEGER | (VARCHAR LPAR integer RPAR) ;// | DATET | TIMET | (CHAR LPAR DIGIT+ RPAR) );
	
typedAttributeList //TYPEDATTRIBUTELIST
	: IDENTIFIER type (COMMA IDENTIFIER type)* ;
	
operand
	: integer | IDENTIFIER | LITERAL;
		
attributeList
	: IDENTIFIER (COMMA IDENTIFIER)* ;
	
openCMD
	: OPEN IDENTIFIER ;
	
closeCMD
	: CLOSE IDENTIFIER ;

showCMD
	: SHOW atomicExpr ;	

writeCMD
	: WRITE IDENTIFIER ;
	
deleteCMD
	: DELETE FROM IDENTIFIER WHERE condition ;
		
exitCMD
	: EXIT ;
	
condition
	: conjunction (DOUBLEOR conjunction)* ;
	
conjunction
	: comparison (DOUBLEAND comparison)* ;
	
comparison
	: operand OPERATION operand | (LPAR condition RPAR);

selection
	: SELECT LPAR condition RPAR atomicExpr ;
	
projection
	: PROJECT LPAR attributeList RPAR atomicExpr ;

atomicExpr
	: IDENTIFIER  | (LPAR expr RPAR) ;
	
renaming
	: RENAME LPAR attributeList RPAR atomicExpr ;
	
union 
	: atomicExpr PLUS atomicExpr ;

difference
	: atomicExpr MINUS atomicExpr ;
	
product 
	:  atomicExpr PRODUCT atomicExpr ;	

expr
	: atomicExpr | selection | projection | renaming | union | difference | product ;

 
insertCMD
	: (INSERT INTO IDENTIFIER VALUES FROM LPAR  (integer | LITERAL) (COMMA (DIGIT+ | LITERAL ) )*  RPAR)
	| (INSERT INTO IDENTIFIER VALUES FROM RELATION expr) ;


query
	: IDENTIFIER LARROW expr SEMICOLON;
	
UPDATEFRAG
	: IDENTIFIER EQUAL DIGIT ;
	
//TYPE
//	: (VARCHAR LPAR DIGIT+ RPAR) | INTEGERT | DATET | TIMET | (CHAR LPAR DIGIT+ RPAR) ;
//	
//fragment TYPEDATTRIBUTE
//	: IDENTIFIER TYPE ;
//	
//TYPEDATTRIBUTELIST
//	: TYPEDATTRIBUTE (COMMA TYPEDATTRIBUTE)* ;

createCMD
	: CREATE TABLE IDENTIFIER LPAR typedAttributeList RPAR PRIMARY KEY LPAR attributeList RPAR;
	
updateCMD
	: UPDATE IDENTIFIER SET UPDATEFRAG (COMMA UPDATEFRAG)* WHERE condition ;

command
	: (openCMD | closeCMD | writeCMD | showCMD | exitCMD | createCMD | updateCMD | insertCMD | deleteCMD ) SEMICOLON;
	
program
	: (query | command) ;		


	
	
	
	