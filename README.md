# kelen_transpiler

## Why am I working on this project?
So after learning about how GPT-2 is a opaque-box which doesn't help linguists learn anything, I got angry and wanted to work on natural language processing in a way that uses/interacts with the field of linguistics. Later after auditing a Complier class and making an extremely useless compiler, I decided I wanted to make some sort of transpiler. Later I learned that GPT-3 is barely able to do arithmetic, but can solve lots of word type problems, and can make lots of art. This all lead to the main idea of this project.

## Project Goal:
Make an clear-box oracle AI which can get a 36 on an ACT exam in the time it takes a person to normally do an ACT exam.
By clear-box I mean that the AI's knowledge and understanding can be comprehended by any programmer.

## Project Strategy:
1. Make a Kelen to TLA+ transpiler which uses some common knowledge structure.
  a. SKIP making a kelen de-abrieviator preprocessor
  b. Make a Kelen lexer
  c. Make a Kelen parser
  d. Make a kelen word to stem converter
  e. Make an abstract syntax tree to code converter
  f. Make a context where the code runs and manages state and prints results.
2. Make a Standard American English to Kelen Translator
3. Make a common knowledge generator.
4. Make a TLA+ output to multiple choice answer key engine.

## Why the conlang Kelen :
Kelen is a conlang which is in universe an alien language. It almost violates one of the universals of language: having verbs. However, it is still a very expressive conlang which could actually be spoken. Additionally, It does something rare for a natural language: excluding pronouns and contractions, Kelen has a context free grammar. Lastly,  Kelen seems to have few enough actions that each action can relate to a clear programtic step in logic. Together these make Kelen a great stepping stone for transversing the natural language-programming language divide. Kelen can be spoken, Kelen can express any thought, Kelen can be parsed and lexed, Kelen might be programmable. Can Kelen be transpiled and compiled into executable code?
### What is a transpiler?
A transpiler is between compiler and a translator. It doesn't produce an executable, but it does change a language from one thing into another.

## Why the ACT:
The ACT is a hard test of knowledge, skill, and intellect which there are freely released practice versions of. The test covers multiple subject which people often think of as having incompatible skills: English, Reading, Math, and Science. The test is also entirely multiple choice, and thus can be answered with TLA+ printing yes/no questions.
