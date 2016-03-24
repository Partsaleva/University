; Sat Feb 07 11:35:47 EET 2015
; 
;+ (version "3.5")
;+ (build "Build 663")
(definstances inst
([fn71448_Class0] of  Bachelor_Program

	(accredited yes)
	(address "15A Vasil Aprilov Blvd.")
	(city "Plovdiv")
	(email "rector@meduniversity-plovdiv.bg")
	(exam "biology")
	(field_name Medicine_HealthSciences)
	(financing State)
	(InGroup [fn71448_Class10001])
	(subject "Nursing Care")
	(telephone "032/602207")
	(universitylName "Medical University - Plovdiv")
	(yearFouded 1945))

([fn71448_Class1] of  Subject_Groups

	(accredited yes)
	(address "15 Tzar Osvoboditel Blvd.")
	(city "Sofia")
	(email "info@uni-sofia.bg")
	(field_name Mathematics_NaturalSciences)
	(financing State)
	(group_name "Mathematics")
	(telephone "02 8623 552")
	(universitylName "Sofia University \"St. Kliment Ohridski\"")
	(yearFouded 1988))

([fn71448_Class10001] of  Subject_Groups

	(accredited yes)
	(field_name Medicine_HealthSciences)
	(financing State)
	(group_name "Public Health"))

([fn71448_Class10002] of  Master_Programm

	(accredited yes)
	(address "15A Vasil Aprilov Blvd.")
	(city "Plovdiv")
	(email "rector@meduniversity-plovdiv.bg")
	(field_name Medicine_HealthSciences)
	(financing Private)
	(group_name "Stomatology")
	(subject_m "Dental Medicine")
	(telephone "032/602207")
	(universitylName "Medical University - Plovdiv")
	(yearFouded 1945))

([fn71448_Class10003] of  Subject_Groups

	(accredited yes)
	(field_name Medicine_HealthSciences)
	(financing State)
	(group_name "Stomatology"))

([fn71448_Class10004] of  Bachelor_Program

	(accredited yes)
	(address "62, San Stefano Str")
	(city "Bourgas")
	(email "e_mavrodieva@bfu.bg")
	(exam "Literature")
	(field_name EconomicSciences_Law)
	(financing Private)
	(group_name "Law")
	(InGroup [fn71448_Class10005])
	(subject "Social Work and Counselling")
	(telephone "056900400")
	(universitylName "Burgas Free University"))

([fn71448_Class10005] of  Subject_Groups

	(accredited yes)
	(field_name EconomicSciences_Law)
	(financing State)
	(group_name "Social Work"))

([fn71448_Class10006] of  Master_Programm

	(accredited yes)
	(address "62, San Stefano Str")
	(city "Bourgas")
	(email "e_mavrodieva@bfu.bg")
	(field_name EconomicSciences_Law)
	(financing Private)
	(group_name "Law")
	(subject_m "Law")
	(telephone "056900400")
	(universitylName "Burgas Free University"))

([fn71448_Class10007] of  Subject_Groups

	(accredited yes)
	(field_name EconomicSciences_Law)
	(financing State)
	(group_name "Law"))

([fn71448_Class62] of  Subject_Groups

	(accredited yes)
	(address "15 Tzar Osvoboditel Blvd.")
	(city "Sofia")
	(email "info@uni-sofia.bg")
	(field_name Mathematics_NaturalSciences)
	(financing State)
	(group_name "Computer Sience")
	(telephone "02 8623 552")
	(universitylName "Sofia University \"St. Kliment Ohridski\"")
	(yearFouded 1988))

([fn71448_Class63] of  Bachelor_Program

	(accredited yes)
	(address "15 Tzar Osvoboditel Blvd.")
	(city "Sofia")
	(email "info@uni-sofia.bg")
	(exam "Math")
	(field_name Mathematics_NaturalSciences)
	(financing State)
	(InGroup [fn71448_Class62])
	(subject "Computer Engineering")
	(telephone "02 8623 552")
	(universitylName "Sofia University \"St. Kliment Ohridski\"")
	(yearFouded 1988))

([fn71448_Class64] of  Bachelor_Program

	(accredited yes)
	(address "15 Tzar Osvoboditel Blvd.")
	(city "Sofia")
	(email "info@uni-sofia.bg")
	(exam "Math")
	(field_name Mathematics_NaturalSciences)
	(financing State)
	(InGroup [fn71448_Class62])
	(subject "Information Systems")
	(telephone "02 8623 552")
	(universitylName "Sofia University \"St. Kliment Ohridski\"")
	(yearFouded 1988))

([fn71448_Class65] of  Master_Programm

	(accredited yes)
	(address "15 Tzar Osvoboditel Blvd.")
	(city "Sofia")
	(email "info@uni-sofia.bg")
	(field_name Mathematics_NaturalSciences)
	(financing Private)
	(matchWith [fn71448_Class64])
	(subject_m "Information Systems (education form: full-time)")
	(telephone "02 8623 552")
	(universitylName "Sofia University \"St. Kliment Ohridski\"")
	(yearFouded 1988))

([fn71448_Class73] of  Master_Programm

	(accredited yes)
	(address "15 Tzar Osvoboditel Blvd.")
	(city "Sofia")
	(email "info@uni-sofia.bg")
	(field_name Mathematics_NaturalSciences)
	(financing State)
	(group_name "Computer Sience")
	(subject_m "Computer Graphics")
	(telephone "02 8623 552")
	(universitylName "Sofia University \"St. Kliment Ohridski\"")
	(yearFouded 1988))

([fn71448_Class74] of  Doctor_Programm

	(accredited yes)
	(address "15 Tzar Osvoboditel Blvd.")
	(city "Sofia")
	(email "info@uni-sofia.bg")
	(field_name Mathematics_NaturalSciences)
	(financing State)
	(group_name "Computer Sience")
	(subject_d "Informatics")
	(telephone "02 8623 552")
	(universitylName "Sofia University \"St. Kliment Ohridski\""))

([fn71448_Class75] of  Doctor_Programm

	(accredited yes)
	(address "15 Tzar Osvoboditel Blvd.")
	(city "Sofia")
	(email "info@uni-sofia.bg")
	(field_name Mathematics_NaturalSciences)
	(financing State)
	(group_name "Mathematics")
	(subject_d "Mathematical Logic")
	(telephone "02 8623 552"))

([fn71448_Class76] of  Comprehensive

	(address_h "Sofia, Mladost 1, Do Bl. 43")
	(admission_after 1)
	(city_h "Sofia")
	(hasAddPrograms Yes)
	(highSchoolName "HIGH SCHOOL 140 IVAN BOGOROV")
	(telephone_h "02 9343373"))

([fn71448_Class77] of  Language

	(address_h "Sofia, ul. Slatinska 35")
	(admission_after 7)
	(city_h "Bourgas")
	(highSchoolName "LANGUAGE HIGH SCHOOL 157 VAIEHO")
	(lang English Spanish)
	(telephone_h "02 9710056"))

([fn71448_Class82] of  Comprehensive

	(address_h "Sofia, bul. Evropa 135")
	(admission_after 1)
	(city_h "Bourgas")
	(hasAddPrograms Yes)
	(highSchoolName "HIGH SCHOOL 137 ANGEL KANCHEV")
	(telephone_h "02 8257353"))

([fn71448_Class83] of  Language

	(admission_after 7)
	(city_h "Sofia")
	(highSchoolName "LANGUAGE HIGH SCHOOL \"Sveta Sofia\"")
	(lang English German Russian Spanish))

([fn71448_Class84] of  Specialized

	(admission_after 8)
	(city_h "Sofia")
	(highSchoolName "PMG \"Acad. L. Chakalov\"")
	(telephone_h "02 862 29 66")
	(typeOfSpec math))

([fn71448_Class85] of  Specialized

	(admission_after 8)
	(city_h "Bourgas")
	(highSchoolName "Sport Shool \"Gen. Vladimir Stoychev\"")
	(telephone_h "02 870 34 81")
	(typeOfSpec sport))

([fn71448_Class86] of  Student

	(city_pref "Sofia")
	(exam_pref "math")
	(nameIt "stud")
	(programm Bachelor)
	(study University)
	(type_of_school "University"))
)