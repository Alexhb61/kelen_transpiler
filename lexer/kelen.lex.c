/*Using REflex instead of flex or lex because I NEED THAT UTF-16 yo*/
/*Definitions go here*/
INANIMATE  				ja?
ANIMATE 				ma?
NONSPECIFIC 			an
LETTER					ā|ē|ī|ū|ō|o|u|e|i|a|m|n|ñ|ŋ|l|λ|r|(rj)|p|t|s|c|k|w|þ|x|j|h
CONSANANT			    m|n|ñ|ŋ|l|λ|r|(rj)|p|t|s|c|k|w|þ|x|j|h
STRONGCONSANANT			m|n|ñ|ŋ|l|λ|r|(rj)
STRONGVOWEL 			ā|ē|ī|ū|ō|o|u
LONGVOWEL				ā|ē|ī|ū|ō
%%
/*rules and actions go here*/


/*Noun rules start here */
{INANIMATE}												BEGIN(Nin)
{ANIMATE}												BEGIN(Nan)
{NONSPECIFIC}											BEGIN(Non)
/*rule 1 exceptions*/
<Nin>{LETTER}+wiē										{yyval = stem_parse(unmorph(yytext,"īj")); return TOK_NSG;}
<Nan>{LETTER}+wiē										{yyval = stem_parse(unmorph(yytext,"īj")); return TOK_NANSG;}
<Non>{LETTER}+wiē										{yyval = stem_parse(unmorph(yytext,"īj")); return TOK_NST;}
/*rule 1 */
<Nin>{LETTER}+{STRONGVOWEL}								{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+{STRONGVOWEL}								{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+{STRONGVOWEL}								{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 2 2nd level exceptions */
<Nin>(pāŋŋien)|(sēttien)|(tārharrien)|(ānnien)|(ōrrien)|(hālien)	{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>(pāŋŋien)|(sēttien)|(tārharrien)|(ānnien)|(ōrrien)|(hālien)	{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>(pāŋŋien)|(sēttien)|(tārharrien)|(ānnien)|(ōrrien)|(hālien)	{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 2 1st level exceptions*/
<Nin>{LETTER}+{LONGVOWEL}{CONSANANT}{1,2}ie/n			{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+{LONGVOWEL}{CONSANANT}{1,2}ie/n			{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+{LONGVOWEL}{CONSANANT}{1,2}ie/n			{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 2 1st level exception thingu*/
<Nan>{LETTER}+{CONSANANT}/((\2)ien)						{yyval = stem_parse(yytext); return TOK_NANPL;}
/*rule 2*/
<Nin>{LETTER}+{STRONGCONSANANT}							{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+{STRONGCONSANANT}							{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+{STRONGCONSANANT}							{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 3 exception*/
<Nin>{LETTER}+ōr/(xe)									{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+ōr/(xe)									{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+ōr/(xe)									{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 3*/
<Nin>{LETTER}+{CONSANANT}{2}/e							{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+{CONSANANT}{2}/e							{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+{CONSANANT}{2}/e							{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 4*/
<Nin>{LETTER}+ēi/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG;}
<Nan>{LETTER}+ēi/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NANSG;}
<Non>{LETTER}+ēi/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NST;}
/*rule 5*/
<Nin>{LETTER}+{CONSANANT}ie								{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+{CONSANANT}ie								{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+{CONSANANT}ie								{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 6 1st level exception 1*/
<Nin>{LETTER}+wāe										{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+wāe										{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+wāe										{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 6 1st level exception 2 HOW COMMON IS THIS EXCEPTION! DOES IT NEED TO BE EXPANDED*/
<Nin>{LETTER}+mā/e										{yyval = stem_parse(yytext); return TOK_NPL;}
<Nan>{LETTER}+mā/e										{yyval = stem_parse(yytext); return TOK_NANCL;}
<Non>{LETTER}+mā/e										{yyval = stem_parse(yytext); return TOK_NCL;}
/*rule 6 1st level exception 3 HOW COMMON IS THIS EXCEPTION! DOES IT NEED TO BE EXPANDED*/
<Nin>{LETTER}+nae										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NPL;}
<Nan>{LETTER}+nae										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NANCL;}
<Non>{LETTER}+nae										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NCL;}
/*rule 6*/
<Nin>{LETTER}+{CONSANANT}(ā|a)e							{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG;}
<Nan>{LETTER}+{CONSANANT}(ā|a)e							{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NANSG;}
<Non>{LETTER}+{CONSANANT}(ā|a)e							{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NST;}
/*rule 7 exception*/
<Nin>{LETTER}+āmīwe										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG;}
<Nan>{LETTER}+āmīwe										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NANSG;}
<Non>{LETTER}+āmīwe										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NST;}
/*rule 7*/
<Nin>{LETTER}+īw/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG;}
<Nan>{LETTER}+īw/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NANSG;}
<Non>{LETTER}+īw/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NST;}
/*rule 3-7 hyperrule*/
<Nin>{LETTER}+/e										{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+/e										{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+/e										{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 8 exceptions*/
<Nin>{LETTER}+cār/a										{yyval = stem_parse(yytext); return TOK_NPL;}
<Nan>{LETTER}+cār/a										{yyval = stem_parse(yytext); return TOK_NANCL;}
<Non>{LETTER}+cār/a										{yyval = stem_parse(yytext); return TOK_NCL;}
/*rule 8 */
<Nin>{LETTER}+/a										{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+/a										{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+/a										{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 9 */
<Nin>{LETTER}+/i										{yyval = stem_parse(yytext); return TOK_NPL;}
<Nan>{LETTER}+/i										{yyval = stem_parse(yytext); return TOK_NANCL;}
<Non>{LETTER}+/i										{yyval = stem_parse(yytext); return TOK_NCL;}
%%
	

