/*Using REflex instead of flex or lex because I NEED THAT UTF-16 yo*/
/*Definitions go here*/
FIRSTPOSSESSED				le?
SECONDPOSSESSED				ri?
THIRDPOSSESSED				sa?
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
{FIRSTPOSSESSED}										BEGIN(N1)
{SECONDPOSSESSED}										BEGIN(N2)
{THIRDPOSSESSED}										BEGIN(N3)
{INANIMATE}											BEGIN(Nin)
{ANIMATE}											BEGIN(Nan)
{NONSPECIFIC}											BEGIN(Non)
/*rule 1 exceptions*/
<N1>{LETTER}+wiē										{yyval = stem_parse(unmorph(yytext,"īj")); return TOK_NSG_1;}
<N2>{LETTER}+wiē										{yyval = stem_parse(unmorph(yytext,"īj")); return TOK_NSG_2;}
<N3>{LETTER}+wiē										{yyval = stem_parse(unmorph(yytext,"īj")); return TOK_NSG_3;}
<Nin>{LETTER}+wiē										{yyval = stem_parse(unmorph(yytext,"īj")); return TOK_NSG;}
<Nan>{LETTER}+wiē										{yyval = stem_parse(unmorph(yytext,"īj")); return TOK_NANSG;}
<Non>{LETTER}+wiē										{yyval = stem_parse(unmorph(yytext,"īj")); return TOK_NST;}
/*rule 1 */
<N1>{LETTER}+{STRONGVOWEL}									{yyval = stem_parse(yytext); return TOK_NSG_1;}
<N2>{LETTER}+{STRONGVOWEL}									{yyval = stem_parse(yytext); return TOK_NSG_2;}
<N3>{LETTER}+{STRONGVOWEL}									{yyval = stem_parse(yytext); return TOK_NSG_3;}
<Nin>{LETTER}+{STRONGVOWEL}									{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+{STRONGVOWEL}									{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+{STRONGVOWEL}									{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 2 2nd level exceptions */
<N1>(pāŋŋien)|(sēttien)|(tārharrien)|(ānnien)|(ōrrien)|(hālien)					{yyval = stem_parse(yytext); return TOK_NSG_1;}
<N2>(pāŋŋien)|(sēttien)|(tārharrien)|(ānnien)|(ōrrien)|(hālien)					{yyval = stem_parse(yytext); return TOK_NSG_2;}
<N3>(pāŋŋien)|(sēttien)|(tārharrien)|(ānnien)|(ōrrien)|(hālien)					{yyval = stem_parse(yytext); return TOK_NSG_3;}
<Nin>(pāŋŋien)|(sēttien)|(tārharrien)|(ānnien)|(ōrrien)|(hālien)				{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>(pāŋŋien)|(sēttien)|(tārharrien)|(ānnien)|(ōrrien)|(hālien)				{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>(pāŋŋien)|(sēttien)|(tārharrien)|(ānnien)|(ōrrien)|(hālien)				{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 2 1st level exceptions*/
<N1>{LETTER}+{LONGVOWEL}{CONSANANT}{1,2}ie/n							{yyval = stem_parse(yytext); return TOK_NSG_1;}
<N2>{LETTER}+{LONGVOWEL}{CONSANANT}{1,2}ie/n							{yyval = stem_parse(yytext); return TOK_NSG_2;}
<N3>{LETTER}+{LONGVOWEL}{CONSANANT}{1,2}ie/n							{yyval = stem_parse(yytext); return TOK_NSG_3;}
<Nin>{LETTER}+{LONGVOWEL}{CONSANANT}{1,2}ie/n							{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+{LONGVOWEL}{CONSANANT}{1,2}ie/n							{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+{LONGVOWEL}{CONSANANT}{1,2}ie/n							{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 2 1st level exception thingu*/
<Nan>{LETTER}+{CONSANANT}/((\2)ien)								{yyval = stem_parse(yytext); return TOK_NANPL;}
/*rule 2*/	
<N1>{LETTER}+{STRONGCONSANANT}									{yyval = stem_parse(yytext); return TOK_NSG_1;}
<N2>{LETTER}+{STRONGCONSANANT}									{yyval = stem_parse(yytext); return TOK_NSG_2;}
<N3>{LETTER}+{STRONGCONSANANT}									{yyval = stem_parse(yytext); return TOK_NSG_3;}
<Nin>{LETTER}+{STRONGCONSANANT}									{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+{STRONGCONSANANT}									{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+{STRONGCONSANANT}									{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 3 exception*/
<N1>{LETTER}+ōr/(xe)										{yyval = stem_parse(yytext); return TOK_NSG_1;}
<N2>{LETTER}+ōr/(xe)										{yyval = stem_parse(yytext); return TOK_NSG_2;}
<N3>{LETTER}+ōr/(xe)										{yyval = stem_parse(yytext); return TOK_NSG_3;}
<Nin>{LETTER}+ōr/(xe)										{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+ōr/(xe)										{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+ōr/(xe)										{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 3*/
<N1>{LETTER}+{CONSANANT}{2}/e									{yyval = stem_parse(yytext); return TOK_NSG_1;}
<N2>{LETTER}+{CONSANANT}{2}/e									{yyval = stem_parse(yytext); return TOK_NSG_2;}
<N3>{LETTER}+{CONSANANT}{2}/e									{yyval = stem_parse(yytext); return TOK_NSG_3;}
<Nin>{LETTER}+{CONSANANT}{2}/e									{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+{CONSANANT}{2}/e									{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+{CONSANANT}{2}/e									{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 4*/
<N1>{LETTER}+ēi/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG_1;}
<N2>{LETTER}+ēi/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG_2;}
<N3>{LETTER}+ēi/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG_3;}
<Nin>{LETTER}+ēi/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG;}
<Nan>{LETTER}+ēi/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NANSG;}
<Non>{LETTER}+ēi/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NST;}
/*rule 5*/
<N1>{LETTER}+{CONSANANT}ie									{yyval = stem_parse(yytext); return TOK_NSG_1;}
<N2>{LETTER}+{CONSANANT}ie									{yyval = stem_parse(yytext); return TOK_NSG_2;}
<N3>{LETTER}+{CONSANANT}ie									{yyval = stem_parse(yytext); return TOK_NSG_3;}
<Nin>{LETTER}+{CONSANANT}ie									{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+{CONSANANT}ie									{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+{CONSANANT}ie									{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 6 1st level exception 1*/
<N1>{LETTER}+wāe										{yyval = stem_parse(yytext); return TOK_NSG_1;}
<N2>{LETTER}+wāe										{yyval = stem_parse(yytext); return TOK_NSG_2;}
<N3>{LETTER}+wāe										{yyval = stem_parse(yytext); return TOK_NSG_3;}
<Nin>{LETTER}+wāe										{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+wāe										{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+wāe										{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 6 1st level exception 2 HOW COMMON IS THIS EXCEPTION! DOES IT NEED TO BE EXPANDED*/
<N1>{LETTER}+mā/e										{yyval = stem_parse(yytext); return TOK_NPL_1;}
<N2>{LETTER}+mā/e										{yyval = stem_parse(yytext); return TOK_NPL_2;}
<N3>{LETTER}+mā/e										{yyval = stem_parse(yytext); return TOK_NPL_3;}
<Nin>{LETTER}+mā/e										{yyval = stem_parse(yytext); return TOK_NPL;}
<Nan>{LETTER}+mā/e										{yyval = stem_parse(yytext); return TOK_NANCL;}
<Non>{LETTER}+mā/e										{yyval = stem_parse(yytext); return TOK_NCL;}
/*rule 6 1st level exception 3 HOW COMMON IS THIS EXCEPTION! DOES IT NEED TO BE EXPANDED*/
<N1>{LETTER}+nae										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NPL_1;}
<N2>{LETTER}+nae										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NPL_2;}
<N3>{LETTER}+nae										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NPL_3;}
<Nin>{LETTER}+nae										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NPL;}
<Nan>{LETTER}+nae										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NANCL;}
<Non>{LETTER}+nae										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NCL;}
/*rule 6*/
<N1>{LETTER}+{CONSANANT}(ā|a)e									{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG_1;}
<N2>{LETTER}+{CONSANANT}(ā|a)e									{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG_2;}
<N3>{LETTER}+{CONSANANT}(ā|a)e									{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG_3;}
<Nin>{LETTER}+{CONSANANT}(ā|a)e									{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG;}
<Nan>{LETTER}+{CONSANANT}(ā|a)e									{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NANSG;}
<Non>{LETTER}+{CONSANANT}(ā|a)e									{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NST;}
/*rule 7 exception*/
<N1>{LETTER}+āmīwe										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG_1;}
<N2>{LETTER}+āmīwe										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG_2;}
<N3>{LETTER}+āmīwe										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG_3;}
<Nin>{LETTER}+āmīwe										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG;}
<Nan>{LETTER}+āmīwe										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NANSG;}
<Non>{LETTER}+āmīwe										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NST;}
/*rule 7*/
<N1>{LETTER}+īw/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG_1;}
<N2>{LETTER}+īw/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG_2;}
<N3>{LETTER}+īw/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG_3;}
<Nin>{LETTER}+īw/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NSG;}
<Nan>{LETTER}+īw/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NANSG;}
<Non>{LETTER}+īw/e										{yyval = stem_parse(unmorph(yytext,"j")); return TOK_NST;}
/*rule 3-7 hyperrule*/
<N1>{LETTER}+/e											{yyval = stem_parse(yytext); return TOK_NSG_1;}
<N2>{LETTER}+/e											{yyval = stem_parse(yytext); return TOK_NSG_2;}
<N3>{LETTER}+/e											{yyval = stem_parse(yytext); return TOK_NSG_3;}
<Nin>{LETTER}+/e										{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+/e										{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+/e										{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 8 exceptions*/
<N1>{LETTER}+cār/a										{yyval = stem_parse(yytext); return TOK_NPL_1;}
<N2>{LETTER}+cār/a										{yyval = stem_parse(yytext); return TOK_NPL_2;}
<N3>{LETTER}+cār/a										{yyval = stem_parse(yytext); return TOK_NPL_3;}
<Nin>{LETTER}+cār/a										{yyval = stem_parse(yytext); return TOK_NPL;}
<Nan>{LETTER}+cār/a										{yyval = stem_parse(yytext); return TOK_NANCL;}
<Non>{LETTER}+cār/a										{yyval = stem_parse(yytext); return TOK_NCL;}
/*rule 8 */
<N1>{LETTER}+/a											{yyval = stem_parse(yytext); return TOK_NSG_1;}
<N2>{LETTER}+/a											{yyval = stem_parse(yytext); return TOK_NSG_2;}
<N3>{LETTER}+/a											{yyval = stem_parse(yytext); return TOK_NSG_3;}
<Nin>{LETTER}+/a										{yyval = stem_parse(yytext); return TOK_NSG;}
<Nan>{LETTER}+/a										{yyval = stem_parse(yytext); return TOK_NANSG;}
<Non>{LETTER}+/a										{yyval = stem_parse(yytext); return TOK_NST;}
/*rule 9 */
<N1>{LETTER}+/i											{yyval = stem_parse(yytext); return TOK_NPL_1;}
<N2>{LETTER}+/i											{yyval = stem_parse(yytext); return TOK_NPL_2;}
<N3>{LETTER}+/i											{yyval = stem_parse(yytext); return TOK_NPL_3;}
<Nin>{LETTER}+/i										{yyval = stem_parse(yytext); return TOK_NPL;}
<Nan>{LETTER}+/i										{yyval = stem_parse(yytext); return TOK_NANCL;}
<Non>{LETTER}+/i										{yyval = stem_parse(yytext); return TOK_NCL;}
%%
	

