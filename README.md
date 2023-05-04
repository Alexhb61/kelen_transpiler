# kelen_transpiler

## Project Cancelled:
This project was too ambitious and I stopped working on it, because I lacked the resources.

## Why am I working on this project?
So after learning about how GPT-2 is a opaque-box which doesn't help linguists learn anything, I got angry and wanted to work on natural language processing in a way that uses/interacts with the field of linguistics. Later after auditing a Complier class and making an extremely useless compiler in my comparative programming languages class, I decided I wanted to make some sort of transpiler. Later I learned that GPT-3 is barely able to do arithmetic, but can solve lots of word type problems, and can make lots of art. This all lead to the main idea of this project. I then randomly happened across the perfect tools for this project when I was watching Jan Misali critique different conlangs, and I was really inspired to make something which worked with the conlang Kelen. I was additionally also exposed to the appropriate programming language to handle the nondeterminism of natural language with PlusCal via my interest in formal specification. 

### Why am I working on such a hard project?
The intent here is to learn useful programming and linguistic skills, and learn why these problems are hard. I know this project might be impossible to do on my own, but I hope to make an interesting enough progress that some computational linguists will want to help me or that I will continue to have fun while the project lasts.

## Project Goal:
Make an clear-box oracle AI which can get a 36 on an ACT exam in the time it takes a person to normally do an ACT exam.
By clear-box I mean that the AI's knowledge and understanding can be comprehended by anyone capable of learning Kelen.

## Project Strategy:
1. Make a [Kelen](https://www.terjemar.net/kelen/kelen.php) to TLA+ transpiler which uses some common knowledge structure.
    1. SKIP making a kelen de-abrieviator preprocessor
    2. Make a Kelen lexer
    3. Make a Kelen parser
    4. Make a kelen word to stem converter
    5. Make an abstract syntax tree to code converter
    6. Make a context where the code runs and manages state and prints results.
2. Make a Standard American English to Kelen Translator
3. Make a common knowledge generator.
4. Make a TLA+ output to multiple choice answer key engine.

## Why the conlang Kelen :
Kelen is a conlang which is in universe an alien language. It almost violates one of the universals of language: having verbs. However, it is still a very expressive conlang which could actually be spoken. Additionally, It does something rare for a natural language: excluding pronouns and contractions, Kelen has a context free grammar. Lastly,  Kelen seems to have few enough actions that each action can relate to a clear programtic step in logic. Together these make Kelen a great stepping stone for transversing the natural language-programming language divide. Kelen can be spoken, Kelen can express any thought, Kelen can be parsed and lexed, Kelen might be programmable. Can Kelen be transpiled and compiled into executable code? I hope to find out.
### What is a transpiler?
A transpiler is between compiler and a translator. It doesn't produce an executable, but it does change a language from one thing into another.

## Why the ACT:
The ACT is a hard test of knowledge, skill, and intellect which there are freely released practice versions of. The test covers multiple subject which people often think of as having incompatible skills: English, Reading, Math, and Science. The test is also entirely multiple choice, and thus can be answered with TLA+ printing yes/no questions.

## Why use TLA+/PlusCal:
So philosophers introduced different modal logics to handle different tenses / moods /modes of natural language meaning. Because I am trying to make an orcale which understands these tenses/moods/modes, it will be productive to have a programing language which sufficiently can handle those moods. TLA stands for the temporal logic of actions, and already has direct support for some of temporal tenses with its [], and <> operators. Furthermore, with TLA+ being designed to handle distributed dynamic systems, TLA+ inherently has the ability to express nondeterministic behaviour. This is useful because large swaths of language behave nondeterministicly. This project plans to use PlusCal because it transpiles to TLA+ and is easier to express programs in. Because Kelen naturally feels like a programming language, the project plans to transpile Kelen to PlusCal then to TLA+.

### What do I mean by nondeterministic programming?
So the type of nondeterministic programming with which most people are familiar is behaviour which relies on pseudorandom number generation to produce variation in behaviour. By nondeterministic programming I mean something which is more similar to how language works. Lets give an example:

Two simple deterministic programming techniques, the switch statement and the if-else statement:
`
switch(a){
   1: call_function(); break;
   2: call_other_function(); break;
   default:
      do_nothing();
   break;
}
if a :
    do_something()
else :
    do_a_different_thing()
`

vs. Two simple nondeterministic programming techniques
`
with a \in range() :
    do_something(a)
end with;
either 
    produce_output_a();
or
    produce_output_b();
end either;
`

So in the deterministic examples we have the control of the program branch and only one branch is executed from the programmer's perspective with one example having two choices and the other having many; however, in the nondeterministic examples, if that pluscal was run, execution itself would split into 'threads' and each 'thread' would take a different branch, but from the programmer's perspective  all branches are executed. So the nondeterminism we are talking about is where one models all possibilities instead of the nondeterminism where one randomly choose one possibility from all possibilities.
