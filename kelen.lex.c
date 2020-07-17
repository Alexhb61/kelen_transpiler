/*Using REflex instead of flex or lex because I NEED THAT UTF-16 yo*/
/*Definitions go here*/
INANIMATE  			ja?
ANIMATE 			ma?
NONSPECIFIC 		an
LETTER				ā|ē|ī|ū|ō|o|u|e|i|a|m|n|ñ|ŋ|l|λ|r|(rj)|p|t|s|c|k|w|þ|x|j|h
CONSANANT			m|n|ñ|ŋ|l|λ|r|(rj)|p|t|s|c|k|w|þ|x|j|h
STRONGCONSANANT		m|n|ñ|ŋ|l|λ|r|(rj)
STRONGVOWEL 		ā|ē|ī|ū|ō|o|u
LONGVOWEL			ā|ē|ī|ū|ō
%%
/*rules and actions go here*/


/*Noun rules start here */
{INANIMATE}															BEGIN(Nin)
{ANIMATE}															BEGIN(Nan)
{NONSPECIFIC}														BEGIN(Non)
/*rule 1 exceptions*/
<Nin>{LETTER}+wiē													{yyval = stem_parse(unmorph(yytext,"īj")); return TOK_NSG;}
<Nan>{LETTER}+wiē													{yyval = stem_parse(unmorph(yytext,"īj")); return TOK_NANSG;}
<Non>{LETTER}+wiē													{yyval = stem_parse(unmorph(yytext,"īj")); return TOK_NST;}
/*rule 1 */
<Nin>{LETTER}+{STRONGVOWEL}											{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+{STRONGVOWEL}											{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+{STRONGVOWEL}											{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 2 2nd level exceptions */
<Nin>(pāŋŋien)|(sēttien)|(tārharrien)|(ānnien)|(ōrrien)|(hālien)	{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>(pāŋŋien)|(sēttien)|(tārharrien)|(ānnien)|(ōrrien)|(hālien)	{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>(pāŋŋien)|(sēttien)|(tārharrien)|(ānnien)|(ōrrien)|(hālien)	{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 2 1st level exceptions*/
<Nin>{LETTER}+{LONGVOWEL}{CONSANANT}{1,2}ie/n						{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+{LONGVOWEL}{CONSANANT}{1,2}ie/n						{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+{LONGVOWEL}{CONSANANT}{1,2}ie/n						{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 2 1st level exception thingu*/
<Nan>{LETTER}+{CONSANANT}/((\2)ien)									{yyval = stem_parse(yytext); return TOK_NANPL;}
/*rule 2*/
<Nin>{LETTER}+{STRONGCONSANANT}										{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+{STRONGCONSANANT}										{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+{STRONGCONSANANT}										{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 3 exception*/
<Nin>{LETTER}+ōr/(xe)												{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+ōr/(xe)												{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+ōr/(xe)												{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 3*/
<Nin>{LETTER}+{CONSANANT}{2}/e										{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+{CONSANANT}{2}/e										{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+{CONSANANT}{2}/e										{yyval = stem_parse(yytext); return TOK_NST;}
%%

