%{
#include <stdlib.h>
#include "parser.h"
/*char *strdup(char *s);*/
%}

ws               [\t ]
nl               [\r]?[\n]
white            ({ws}*)
comment          "/*"([^*]*|[*]+[^*/])*"*"+"/"
digit            [0-9]
ident            [A-Za-z][A-Za-z_0-9]*

%%

{white}          { /* Ignored */ }
{comment}        { /* Ignored */ }
"Variables"      { return TVAR; }
"Definitions"    { return TDEF; }
"Equations"      { return TEQN; }
"Initial states" { return TINIT; }
"Transitions"    { return TTRANS; }
"Properties"     { return TPROP; }
{nl}             { yylineno++; return TNL; }
{digit}+         { yylval.value = atoi(yytext); return TNUM; }
"true"           { return TTT; }
"True"           { return TTT; }
"TRUE"           { return TTT; }
"false"          { return TFF; }
"False"          { return TFF; }
"FALSE"          { return TFF; }
"AX"             { return TAX; }
"AG"             { return TAG; }
"AF"             { return TAF; }
"A"              { return TA; }
"EX"             { return TEX; }
"EG"             { return TEG; }
"EF"             { return TEF; }
"E"              { return TE; }
"X"              { return TX; }
"F"              { return TF; }
"G"              { return TG; }
"U"              { return TU; }
"R"              { return TR; }
{ident}          { yylval.name = strdup(yytext); return TIDENT; }
"\\/"            { return TOR; }
"/\\"            { return TAND; }
"'"              { return TPRIME; }
"+"              { return TPLUS; }
"-"              { return TMINUS; }
"*"              { return TMULT; }
"/"              { return TDIV; }
"%"              { return TMOD; }
"^"              { return TPOW; }
"<="             { return TLE; }
">="             { return TGE; }
"<"              { return TLT; }
">"              { return TGT; }
"="              { return TEQ; }
"!="             { return TNEQ; }
"!"              { return TNOT; }
"("              { return TLPAR; }
")"              { return TRPAR; }
"["              { return TLBRA; }
"]"              { return TRBRA; }
","              { return TCOMMA; }
":"              { return TSEMI; }
"->"             { return TARROW; }
"?"		 { return TQMARK; }
"~"		 { return TTIL; }
.                { fprintf(stderr, "Error: unknown char '%s'\n", yytext); exit(1); }
%%
