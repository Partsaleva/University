(defglobal ?*logging* = 1)

(deffunction logmsg (?msg $?args)
	(if (= ?*logging* 1) 
		then
		(printout t ?msg ?args crlf)))
		
		

(deffunction symbolToString (?symb)
	(implode$ (create$ ?symb))
)

(deffunction ask-question (?question)
	(printout t ?question)
	(read))

(deffunction ask-multiple-choice-question (?question $?allowed-values)
   (bind ?answer (ask-question ?question))
   (logmsg "Given answer is: " ?answer " Allowed values are: " ?allowed-values)
   (while (not (member ?answer ?allowed-values)) do
      (bind ?answer (ask-question ?question))
      (logmsg "Bad answer: " ?answer  " Allowed values are: " ?allowed-values)
	  )
   ?answer)
 
(deffunction ask-open-question (?question)
	(bind ?answer (ask-question ?question))
	(while (not (lexemep ?answer)) do
		(bind ?answer (ask-question ?question)))
	?answer)
 
(defrule fill-info	
	(initial-fact)
	=>
	(bind ?stud(ask-multiple-choice-question "What type of educational institution you are looking for, University or High School (U/H)?  " (create$ U H) ))
	(assert (study ?stud))
	(if ( eq ?stud H )
	then (bind ?sch(ask-multiple-choice-question "What type of School you are looking for? Comprehensive, Language or Specialized? . Enter C/L/S  " (create$ C L S)))
	(assert (school ?sch))
	(if (eq ?sch C)
	then(bind ?addp(ask-multiple-choice-question "Do you want to have additional education?(Y/N)  " (create$ Y N) ))
	(assert (addprog ?addp))			
	(bind ?lg(ask-multiple-choice-question "What language you want to study?English,German,Russian,Spanish? Enter: E/G/R/S  " (create$ E G R S) ))
	(assert (lang ?lg)))				
	(bind ?ty(ask-multiple-choice-question "What type? (sport, math, sience, art)Enter SP/M/S/A  " (create$ SP M S A) ))
	(assert (typeOf ?ty))
	(bind ?ad(ask-multiple-choice-question "Admission after 1,7 or 8th grade?   " (create$ 1 7 8) ))
	(assert (admission ?ad))
	(bind ?c(ask-open-question "City?  "))
	(assert (city ?c))
	)
)


(defrule compr1
(study H)
(school C)
(addprog Y)
(admission 1)
(city Bourgas)
?ins11<-(object (is-a Comprehensive) (highSchoolName "HIGH SCHOOL 137 ANGEL KANCHEV"))
=>
(printout t " " (send ?ins11 print) crlf )
)

(defrule compr2
(study H)
(school C)
(addprog Y)
(admission 1)
(city Sofia)
?ins12<-(object (is-a Comprehensive) (highSchoolName "HIGH SCHOOL 140 IVAN BOGOROV"))
=>
(printout t " " (send ?ins12 print) crlf )
)
 

(defrule lang1
(study H)
(school L)
(admission 7)
(city Sofia)
?ins13<-(object (is-a Language) (highSchoolName "LANGUAGE HIGH SCHOOL Sveta Sofia"))
=>
(printout t " " (send ?ins13 print) crlf  )
)

(defrule lang2
(study H)
(school L)
(admission 7)
(city Bourgas)
?ins14<-(object (is-a Language) (highSchoolName "LANGUAGE HIGH SCHOOL 157 VAIEHO"))
=>
(printout t " " (send ?ins14 print) crlf  )
)

(defrule spec1
(study H)
(school S)
(admission 8)
(typeOf M) 
(city Sofia)
?ins15<-(object (is-a Specialized) (highSchoolName "PMG Acad. L. Chakalov"))
=>
(printout t " " (send ?ins15 print) crlf  )
)
(defrule spec2
(study H)
(school S)
(admission 8)
(typeOf SP)
(city Sofia)
?ins16<-(object (is-a Specialized) (highSchoolName "Sport Shool Gen Vladimir Stoychev"))
=>
(printout t " " (send ?ins16 print) crlf )
)