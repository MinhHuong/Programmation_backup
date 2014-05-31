#include <iostream>
#include <cstdlib>
#include <string>
#include "Pile.h"
#include "token.h"
#include "main.h"

using namespace std;

// ----------------------------------------------------------------------------
// Quelques fonctions utiles.


//- Affiche le message [msg] sur la sortie standard et force l'arret du programme.
//- @param msg le message a afficher.
void erreur( const string & msg )
{
  cout << msg << endl;
  exit(1);
}

//- @return 'true' si l'expression [expr] est un operateur: /+-*
bool estUnOperateur( const string & expr )
{
  bool op = false;
  switch ( expr[ 0 ] ) // teste juste le premier caractere.
    {
    case '*': 
    case '/':
    case '+':
    case '-':
      op = true;
    }
  return op;
}

//- @return 'true' si l'expression [expr] est un nombre flottant.
bool estUnNombre( const string & expr )
{
  return isdigit( expr[ 0 ] ); // teste juste le premier caractere.
}

//- @return la valeur de l'expression numerique [expr_num].
//- NB: vous devez verifier avant avec la fonction 'estUnNombre' si vous
//- manipulez bien une expression numerique.
float valeur( const string & expr_num )
{
  return atof( expr_num.c_str() );
}

//- Retourne la priorite d'un operateur. Plus le nombre retourne est grand, 
//- plus l'operateur est prioritaire.
//- @param op un operateur.
//- @return la priorite de l'operateur [op].
int priorite( char op )
{
  int prio = 0;
  switch ( op )
    {
    case '*': 
    case '/':
      prio = 2;
      break;
    case '+':
    case '-':
      prio = 1;
    }
  return prio;
}

// ----------------------------------------------------------------------------
//- Exemple.
//- Decompose l'expression [expr_complete] en nombres, operateurs, et autres
//- (genre parentheses).
//- @param expr_complete une expression arithmetique.
void analyseExpr( string expr_complete )
{
  int indice = 0;
  string expr;
  
  // Prend la premiere expression.
  // NB: indice est incremente dans 'nextArg'.
  expr = nextArg( expr_complete, indice );
  while ( expr != "" )
  {
    if ( estUnNombre( expr ) )
      cout << "nombre : " << valeur( expr ) << endl;
    else if ( estUnOperateur( expr ) )
      cout << "operateur : " << expr << endl;
    else
      cout << "autres : " << expr << endl;

    // Prend l'expression suivante.
    // NB: indice est incremente dans 'nextArg'.
    expr = nextArg( expr_complete, indice );
  }
}


// ----------------------------------------------------------------------------
//- Exercice 1.
//- Objectif: Evaluer l'expression postfixee [expression].
//- @param expression une expression postfixee.
//- @return la valeur de l'expression [expression].
float evalExprPost( string expression )
{
  int indice = 0;
  int a,b,result;
  Pile<float> operand;

  string expr = nextArg( expression, indice );

  while ( expr != "" ) 
    {
      if ( estUnNombre(expr) )
	operand.empiler( valeur(expr) );
      
      if ( estUnOperateur(expr) )
	{
	  a = operand.valeurSommet();
	  operand.depiler();

	  b = operand.valeurSommet();
	  operand.depiler();

	  result = oper2(b, expr[0],a);
	  operand.empiler(result);
	}

      expr = nextArg( expression, indice );
    }
  
  return result;
}

//- Effectue l'operation [op] avec comme operande gauche [valg] et operande
//- droite [vald], puis retourne le resultat.
//- @param valg l'operande gauche.
//- @param op l'operateur ( '+', '-', '*', ou '/' ).
//- @param vald l'operande droite.
float oper2( float valg, char op, float vald )
{
  switch( op ) 
    {
    case '+':
      {
	return ( valg + vald );
	break;
      }

    case '-':
      {
	return ( valg - vald );
	break;
      }

    case '*':
    case 'x':
      {
	return ( valg * vald );
	break;
      }

    case ':':
    case '/':
      {
	if ( vald==0 )
	  erreur("Erreur : Division par zero.");
	return ( valg / vald );
	break;
      }
    }
}

// ----------------------------------------------------------------------------
//- Exercice 2.
//- Objectif: identique a l'exercice 1, sauf qu'il est demande de verifier 
//- l'integrite de l'expression [expression] donnee en entree.
//- Vous testerez entre autres que l'expression contient le bon nombre d'operateurs
//- pour le nombre d'operandes (et vice-versa). Vous pourrez aussi tester que
//- l'expression ne contient pas de symboles inconnus.
//- @param expression une expression postfixee.
//- @return la valeur de l'expression [expression].
float evalSecuriseeExprPost( string expression )
{
  int indice = 0, nb_operateur = 0, nb_operand = 0;
  string expr = nextArg( expression, indice );

  while ( expr != "" )
    {
      if ( estUnNombre(expr) )
	nb_operand++;
      else if ( estUnOperateur(expr) )
	nb_operateur++;
      else if ( expr=="(" || expr==")" )
	; 
      else
	erreur("Symbole inconnue. Le programme s'arrete.");

      expr = nextArg( expression, indice );
    }

  if ( nb_operand-nb_operateur!=1 )
    erreur("Mauvais nombre d'operands pour des operateurs.");
  
  return ( evalExprPost( expression ) );
}

// ----------------------------------------------------------------------------
//- Exercice 3.
//- Objectif: transformer l'expression infixee [expression] en une expression 
//- postfixee. Dans cet exercice, [expression] ne contient pas de parentheses.
//- @param expression une expression infixee.
//- @return l'expression postfixee correspondante.
/*

ALGORITHME :

  1) Si expr est un operand --> afficher expr
  
  2) Si expr est un operateur :
       + Si le pile est vide --> empiler expr
       + Si priorite(expr) > priorite(pile.valeurSommet) --> empiler expr
       + Si priorite(expr) = priorite(pile.valeurSommet) --> afficher(pile.valeurSommet), depiler, empiler expr
       + Sinon, afficher toutes les valeurs dans le pile, (toush1+2*3-4*6/3

--> 1 2 3 * + 4 6 * 3 / -

*/
string exprInfVersExprPost( string expression )
{
  int indice = 0;
  string expr = nextArg( expression, indice );
  string postfix="";
  Pile<char> op;

  while ( expr!="" )
    {
      if ( estUnNombre(expr) )
	postfix += expr + " ";

      if ( estUnOperateur(expr) )
	{
	  if ( op.pileVide() )
	    op.empiler( expr[0] );
	  else if ( priorite( expr[0] ) > priorite( op.valeurSommet() ) )
	      op.empiler( expr[0] );
	  else if ( priorite( expr[0] ) == priorite( op.valeurSommet() ) )
	    {
	      postfix += string(1, op.valeurSommet() ) + " ";
	      op.depiler();
	      op.empiler(expr[0]);	      
	    }
	  else
	    {
	      while ( !op.pileVide() )
		{
		  postfix += string( 1, op.valeurSommet() ) + " ";
		  op.depiler();
		}

	      op.empiler(expr[0]);
	      //postfix += expr + " ";
	    }
	}

      expr = nextArg( expression, indice );
    }

  while ( !op.pileVide() )
    {
      postfix += string( 1, op.valeurSommet() ) + " ";
      op.depiler();
    }

  return postfix;
}

 // ----------------------------------------------------------------------------
 //- Exercice 4.
 //- Objectif: transformer l'expression infixee [expression] en une expression 
 //- postfixee. Dans cet exercice, [expression] peut contenir des parentheses.
 //- @param expression une expression infixee.
 //- @return l'expression postfixee correspondante.

 string exprInfVersExprPost2( string expression )
 {
   int indice = 0;
   string expr = nextArg ( expression, indice );
   string postfix = "";
   Pile<char> op;

   while ( expr!="" )
     {
       if ( estUnNombre(expr) )
	 postfix += expr + " ";
       
       if ( estUnOperateur(expr) )
	 {
	   if ( op.pileVide() )
	     op.empiler( expr[0] );
	   else
	     {
	       if ( priorite(expr[0]) > priorite(op.valeurSommet()) )
		 op.empiler( expr[0] );
	       else if ( priorite(expr[0])==priorite(op.valeurSommet()) )
		 {
		   postfix += string( 1, op.valeurSommet() ) + " ";
		   op.depiler();
		   op.empiler(expr[0]);
		 }
	       else
		 {
		   while ( !op.pileVide() )
		     {
		       postfix += string ( 1, op.valeurSommet() ) + " ";
		       op.depiler();
		     }
		   
		   op.empiler(expr[0]);
		 }
	     }
	 }
 
       if ( expr=="(" )
	 {
	   postfix += expr + " ";
	   op.empiler(expr[0]);
	 }
       
       if ( expr==")" ) 
	 {
	   while ( op.valeurSommet()!='(' )
	     {
	       postfix += string( 1, op.valeurSommet() ) + " ";
	       op.depiler();
	     }
	   op.depiler();
	   postfix += expr + " ";
	 }
       
       expr = nextArg( expression, indice );
     }

   while ( !op.pileVide() )
     {
       postfix += string( 1, op.valeurSommet() ) + " ";
       op.depiler();
     }
   
   return postfix;
 }

 //- Programme principal.
 int main()
 {
   string expression;
   getline( cin, expression );

   cout << exprInfVersExprPost2( expression ) << endl;

  return 0;
}
