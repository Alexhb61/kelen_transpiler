Example: AGENT FREE EXAMPLE 
The dog is black.
The black thing is a husky.
The husky is wagging.
Is the dog wagging?
COMPLILED
REFERANTS = <<>> \\sequence of sets.
SC = 0//// needs to be initially true not finally true
AGENT_I = 0
MODEL VALUES : DOG BLACK HUSKY WAG
GET_REFERENT(properties) ==
	 CHOOSE index \in 1..len(REFERANTS) :
		/\ properties \subseteq REFERENTS[index]
		/\ \A x \in 1..len(REFERANTS):
			properties \subseteq REFERENTS[index] => x <= index
SC = 0 => SC'’ = 1
 /\ (	\/( AGENT_I’= GET_REFERANT({DOG}) ) 
		\/ ( REFERANTS’ = Append(REFERENTS, {DOG} )  
/\ AGENT_I’ = len(REFERANTS))
	/\ (REFERENT’’[AGENT_I’] = REFERENT’[AGENT_I’] \union {BLACK})
...
