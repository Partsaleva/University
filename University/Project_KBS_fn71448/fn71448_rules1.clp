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
	
;;***********************************************************

;;***********************************************************
(defrule fill-info1
	(initial-fact)
	=>
	(bind ?stud(ask-multiple-choice-question "What type of educational institution you are looking for, University or High School (U/H)?  " (create$ U H) ))
	(assert (study ?stud))      
	(if ( eq ?stud U )
	then (bind ?prog(ask-multiple-choice-question "What program you want to follow? Bachelor, Master or Doctor. Enter B/M/D  "(create$ B M D)))
	(assert (programm ?prog)) 
	(if (eq ?prog B)
	then (bind ?ex(ask-open-question "With what exam you will apply?(biology, math, literature)  "))
	(assert (exam ?ex))) 	
	(bind ?gr(ask-open-question "In which field you want to educate? (Mathemathics, Computer_Sience,Social_Work,Public_Health, Law..) "))
	(assert (group ?gr))
	(bind ?f(ask-multiple-choice-question "State or Private financing?(S/P)  "(create$ S P)))
	(assert (finan ?f))
	(bind ?c(ask-open-question "City?  "))
	(assert (city ?c))
	)	
)

(defrule bachelor1
(study U)
(programm B)
(exam math)
(group Computer_Sience)
(city Sofia)
?ins1<-(object (is-a Bachelor_Program) (subject "Computer Engineering"))
?ins2<-(object (is-a Bachelor_Program) (subject "Information Systems"))
=>
(printout t " " (send ?ins1 print) crlf (send ?ins2 print) crlf )
)

(defrule bachelor2
(study U)
(programm B)
(exam biology)
(group Public_Health)
(city Plovdiv)
?ins3<-(object (is-a Bachelor_Program) (subject "Nursing Care"))
=>
(printout t " " (send ?ins3 print) crlf  )
)
 
(defrule bachelor3
(study U)
(programm B)
(exam literature)
(group Social_Work)
(city Bourgas)
?ins4<-(object (is-a Bachelor_Program) (subject "Social Work and Counselling"))

=>
(printout t " " (send ?ins4 print) crlf  )
)

(defrule master1
(study U)
(programm M)
(group Computer_Sience)
(finan P)
(city Sofia)
?ins5<-(object (is-a Master_Programm) (subject_m "Computer Graphics"))
?ins6<-(object (is-a Master_Programm) (subject_m "Information Systems (education form: full-time)"))
=>
(printout t " " (send ?ins5 print) crlf (send ?ins6 print) crlf )
)

(defrule master2
(study U)
(programm M)
(group Stomatology)
(finan P)
(city Plovdiv)
?ins7<-(object (is-a Master_Programm) (subject_m "Nursing Care"))
=>
(printout t " " (send ?ins7 print) crlf )
)
 
(defrule master3
(study U)
(programm M)
(group Law)
(finan P)
(city Bourgas)
?ins8<-(object (is-a Master_Programm) (subject_m "Social Work and Counselling"))
=>
(printout t " " (send ?ins8 print) crlf )
)

(defrule doctor1
(study U)
(programm D)
(group Computer_Sience)
(finan P)
(city Sofia)
?ins9<-(object (is-a Doctor_Programm) (subject_d "Informatics"))
=>
(printout t " " (send ?ins9 print) crlf)
)
 
(defrule doctor2
(study U)
(programm D)
(group Mathematics)
(finan P)
(city Sofia)
?ins10<-(object (is-a Doctor_Programm) (subject_d "Mathematical Logic"))

=>
(printout t " " (send ?ins10 print) crlf  )
)

;salience 15 because this rule should interrupt the search
(defrule end-search-fail (declare (salience 15))
	?state <- (searching-state insearch)
	(found-instances)
	=>
	(retract ?state)
	(assert (searching-state endsearch))
	(printout t "No match found!" crlf)
)

;salience 5 because this rule should be fired after the search
(defrule end-search-found (declare (salience 5))
	?state <- (searching-state insearch)
	(found-instances $?x)
	=>
	(retract ?state)
	(assert (searching-state endsearch))
	(printout t "Found result:" crlf)
	(bind ?allfound $?x)
	(while (> (length$ ?allfound) 0)
		do
		(send (instance-name (nth$ 1 ?allfound)) print)
		(bind ?allfound (rest$ ?allfound))
	)
)
