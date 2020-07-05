\* SET MODEL VALUES = DOG BLACKNESS HUSKY WAGGING STATE
---- MODULE dog_example ----
(*
The dog is black.
The black thing is a husky.
The husky is wagging.
Is the dog wagging?

COMPILED below
*)

\* TLA+ code
CONCEPT_INDICIES = [DOG |-> 1 , BLACKNESS |-> 2 , HUSKY |-> 3 , WAGGING |-> 4, STATE |-> 5 ]
(* --algorithm dog_example
Variables IS_REFERANTS = <<>>, AGENT_I = 0, 
	    CONCEPTS = <<[],[],[],[]>>;
define
GET( REFERANTS, values) == 
LET has(qualities, referant) == 
		/\ DOMAIN qualities \subseteq DOMAIN referent
		/\ \A i \in DOMAIN qualities :
			qualities[i] \subseteq referent[i]
 IN CHOOSE index \in 0..len(REFERANTS) :
		/\ index \= 0 =>
/\  has(values, REFERENTS[index])
/\ \A x \in 1..len(REFERANTS):
				has(values, REFERENTS[x]) => x <= index
		/\ index = 0 =>
			\A x \in 1..len(REFERANTS) :
				~ has(values, REFERENTS[x])
end define;
define 
COMBINE(a,b) == 
[x \in DOMAIN a \union DOMAIN b |->
IF x \in DOMAIN a
THEN IF x \in DOMAIN b
THEN b[x] \union a[x]
ELSE a[x]
	ELSE b[x] ]
end define
define
MODIFY(referants, index, new) ==
[ i \in DOMAIN referants |->
IF i = index
THEN new
ELSE referants[i] ]	
end define
macro MAKE(role, referents, values)
begin
	referents := Append(referents, values);
	role := len(referents);
end macro;
macro SETUP(role, referants, values)
begin
	IF GET(referants, values) = 0
	THEN MAKE(role, referants, values)
	ELSE role := GET(referants, value)
end macro;

begin
S1_setup:
	SETUP(AGENT_I, IS_REFERENTS, [STATE |-> { DOG}] )
S1_exec:
	IS_REFERENTS := MODIFY(IS_REFERENTS, AGENT_I, 
COMBINE(IS_REFERENTS[AGENT_I] , [STATE |-> {BLACK}] ) );
S2_setup:
	SETUP(AGENT_I, IS_REFERENTS, [STATE |-> { BLACK}] )
S2_exec:
	IS_REFERENTS := MODIFY(IS_REFERENTS, AGENT_I, 
COMBINE(IS_REFERENTS[AGENT_I] , [STATE |-> {HUSKY}] ) );
S3_setup:
	SETUP(AGENT_I, IS_REFERENTS, [STATE |-> { HUSKY}] )
S3_exec:
	IS_REFERENTS := MODIFY(IS_REFERENTS, AGENT_I, 
COMBINE(IS_REFERENTS[AGENT_I] , [STATE |-> {WAGGING}] ) );
S4_setup:
	SETUP(AGENT_I, IS_REFERENTS, [STATE |-> { DOG}] )
S4_exec:
	print WAGGING \in IS_REFERENTS[AGENT_I][STATE]
end algorithm; *)
====
