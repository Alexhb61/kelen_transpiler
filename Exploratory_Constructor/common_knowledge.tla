(*
This is a first attmept at creating the common knowledge execution portion of the code.
What is the common knowledge execution? So when people say things, there is the meaning 
of the words they say -the semantic content-, but there is also the meaning of the sentence 
as a whole -the pragmatic content-. In the context of the serious tone of the ACT, we THEORIZE
that the gap between the pragmatic and semantic content is merely the simple "logical" 
implications of the sentence. But that theory might be wrong because I'm not a linguist.
*)

SET MODEL VALUES : STATE IN DOG 
(* --algorithm common knowledge
variables labels = [<<STATE,DOG>> |->"STATE_DOG", IN |-> "IN" ], previous_ch =<<>>, cur_ch = << >>;

define switch(ch) == 
  pc'= labels[ch] /* does this work?
end define;

procedure state_dog()
/* DO SOME LOGIC on all the global variable /// there might be multiple common logics to do
/* THEN ADD CHANGES TO cur_ch if no changes then don't
end procedure;
procedure in()
/* DO SOME LOGIC on all the global variables
/* THEN ADD CHANGES TO cur_ch if no changes then don't
end procedure;

procedure run_ck() begin
variable small_ch = FALSE;
  OUTER_LOOP:
    while Len(cur_ch) > 0 do
      SHIFT:
        previous_ch := cur_ch  || cur_ch := << >>;
      INNER_LOOP:
        while Len(previous_ch) > 0 do
          POP:
            small_ch := Head(previous_ch) || previous_ch := Tail(previous_ch) ;    
          SWITCH:
            switch(small_ch);
              STATE_DOG:
                call state_dog();
                goto END_SWITCH;
              IN:
                call in();
                goto END_SWITCH:
              END_SWITCH:
        end while;
    end while;
end procedure;



end algorithm; *)
