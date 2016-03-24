; Sat Feb 07 11:35:47 EET 2015
; 
;+ (version "3.5")
;+ (build "Build 663")


(defclass %3ACLIPS_TOP_LEVEL_SLOT_CLASS "Fake class to save top-level slot information"
	(is-a USER)
	(role abstract)
	(single-slot universitylName
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot highSchoolName
		(type STRING)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot city_h
		(type STRING)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(multislot lang
		(type SYMBOL)
		(allowed-values English German Russian Spanish)
		(cardinality 1 ?VARIABLE)
		(create-accessor read-write))
	(single-slot masterSubject
		(type STRING)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot isInGroup
		(type INSTANCE)
;+		(allowed-classes Subject_Groups)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot InGroup
		(type INSTANCE)
;+		(allowed-classes Subject_Groups)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot type_of_school
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot address_h
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot hasAddPrograms
		(type SYMBOL)
		(allowed-values Yes No)
		(default Yes)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot nameIt
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot hasField
		(type INSTANCE)
;+		(allowed-classes Fields_of_Study)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(multislot field
		(type SYMBOL)
		(cardinality 1 ?VARIABLE)
		(create-accessor read-write))
	(multislot exam_pref
		(type STRING)
		(create-accessor read-write))
	(single-slot admission_after
		(type INTEGER)
		(range 1 9)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot study
		(type SYMBOL)
		(allowed-values University HighSchool)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot subject_d
		(type STRING)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot subject
		(type STRING)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot doctorSubject
		(type STRING)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot financing
		(type SYMBOL)
		(allowed-values State Private)
		(default State)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot subject_m
		(type STRING)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot accredited
		(type SYMBOL)
		(allowed-values yes no)
		(default yes)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot programm
		(type SYMBOL)
		(allowed-values Bachelor Master Doctor)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot telephone
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot type
		(type SYMBOL)
		(allowed-values language specialized comprehensive)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(multislot city_pref
		(type STRING)
		(cardinality 1 ?VARIABLE)
		(create-accessor read-write))
	(single-slot group_name
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot typeOfSpec
		(type SYMBOL)
		(allowed-values sport math sience art)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot telephone_h
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot email
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot field_name
		(type SYMBOL)
		(allowed-values Agricultural_and_Forest_Sciences Art_Music_Design EconomicSciences_Law Engineering_Sciences Humanities_and_Social_Sciences Language_and_Cultural_Studies Mathematics_NaturalSciences Medicine_HealthSciences)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot address
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(multislot exam
		(type STRING)
		(cardinality 1 ?VARIABLE)
		(create-accessor read-write))
	(single-slot matchWith
		(type INSTANCE)
;+		(allowed-classes Bachelor_Program)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot yearFouded
		(type INTEGER)
		(range 1800 2015)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot city
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write)))

(defclass Study
	(is-a USER)
	(role abstract))

(defclass University
	(is-a Study)
	(role abstract)
	(single-slot universitylName
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot financing
		(type SYMBOL)
		(allowed-values State Private)
		(default State)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot accredited
		(type SYMBOL)
		(allowed-values yes no)
		(default yes)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot telephone
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot yearFouded
		(type INTEGER)
		(range 1800 2015)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot email
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot address
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot city
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write)))

(defclass Fields_of_Study
	(is-a University)
	(role abstract)
	(single-slot field_name
		(type SYMBOL)
		(allowed-values Agricultural_and_Forest_Sciences Art_Music_Design EconomicSciences_Law Engineering_Sciences Humanities_and_Social_Sciences Language_and_Cultural_Studies Mathematics_NaturalSciences Medicine_HealthSciences)
;+		(cardinality 1 1)
		(create-accessor read-write)))

(defclass Subject_Groups
	(is-a Fields_of_Study)
	(role concrete)
	(pattern-match reactive)
	(single-slot group_name
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write)))

(defclass Bachelor_Program
	(is-a Subject_Groups)
	(role concrete)
	(pattern-match reactive)
	(single-slot subject
		(type STRING)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(multislot exam
		(type STRING)
		(cardinality 1 ?VARIABLE)
		(create-accessor read-write))
	(single-slot InGroup
		(type INSTANCE)
;+		(allowed-classes Subject_Groups)
;+		(cardinality 0 1)
		(create-accessor read-write)))

(defclass Master_Programm
	(is-a Subject_Groups)
	(role concrete)
	(pattern-match reactive)
	(single-slot matchWith
		(type INSTANCE)
;+		(allowed-classes Bachelor_Program)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot subject_m
		(type STRING)
;+		(cardinality 1 1)
		(create-accessor read-write)))

(defclass Doctor_Programm
	(is-a Subject_Groups)
	(role concrete)
	(pattern-match reactive)
	(single-slot subject_d
		(type STRING)
;+		(cardinality 1 1)
		(create-accessor read-write)))

(defclass HighSchool "Средни общообразователни училища. \nСпециализирани училища със засилено изучаване на чужди езици (езикови гимназии)\nСпециализирани средни училища(математика, хуманитарни науки, спорт, изкуства)"
	(is-a Study)
	(role abstract)
	(single-slot highSchoolName
		(type STRING)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot city_h
		(type STRING)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot address_h
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(single-slot admission_after
		(type INTEGER)
		(range 1 9)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot telephone_h
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write)))

(defclass Comprehensive "Средни общообразователни училища."
	(is-a HighSchool)
	(role concrete)
	(pattern-match reactive)
	(single-slot hasAddPrograms
		(type SYMBOL)
		(allowed-values Yes No)
		(default Yes)
;+		(cardinality 1 1)
		(create-accessor read-write)))

(defclass Language "Специализирани училища със засилено изучаване на чужди езици (езикови гимназии)"
	(is-a HighSchool)
	(role concrete)
	(pattern-match reactive)
	(multislot lang
		(type SYMBOL)
		(allowed-values English German Russian Spanish)
		(cardinality 1 ?VARIABLE)
		(create-accessor read-write)))

(defclass Specialized "Специализирани средни училища(математика, хуманитарни науки, спорт, изкуства)"
	(is-a HighSchool)
	(role concrete)
	(pattern-match reactive)
	(single-slot typeOfSpec
		(type SYMBOL)
		(allowed-values sport math sience art)
;+		(cardinality 1 1)
		(create-accessor read-write)))

(defclass Student
	(is-a USER)
	(role concrete)
	(pattern-match reactive)
	(single-slot type_of_school
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(multislot exam_pref
		(type STRING)
		(create-accessor read-write))
	(single-slot study
		(type SYMBOL)
		(allowed-values University HighSchool)
;+		(cardinality 1 1)
		(create-accessor read-write))
	(single-slot programm
		(type SYMBOL)
		(allowed-values Bachelor Master Doctor)
;+		(cardinality 0 1)
		(create-accessor read-write))
	(multislot city_pref
		(type STRING)
		(cardinality 1 ?VARIABLE)
		(create-accessor read-write))
	(single-slot nameIt
		(type STRING)
;+		(cardinality 0 1)
		(create-accessor read-write)))