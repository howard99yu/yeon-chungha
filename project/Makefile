main.o:main.cpp function.h selection.h display.h search.h 
	g++ -c main.cpp

add_record.o:add_record.cpp function.h display.h
	g++ -c add_record.cpp

delete_element.o:delete_element.cpp function.h search.h
	g++ -c delete_element.cpp

display.o:display.cpp display.h 
	g++ -c display.cpp

analysis.o:analysis.cpp function.h display.h
	g++ -c analysis.cpp

budget.o:budget.cpp function.h
	g++ -c budget.cpp

display_search.o:display_search.cpp display.h 
	g++ -c display_search.cpp


grow_accountlist.o:grow_accountlist.cpp function.h 
	g++ -c grow_accountlist.cpp


load_accountlist.o:load_accountlist.cpp function.h display.h
	g++ -c load_accountlist.cpp


print_accountlist.o:print_accountlist.cpp function.h display.h
	g++ -c print_accountlist.cpp


save_accountlist.o:save_accountlist.cpp function.h 
	g++ -c save_accountlist.cpp


search_amount.o:search_amount.cpp search.h display.h
	g++ -c search_amount.cpp


search_date.o:search_date.cpp function.h search.h display.h
	g++ -c search_date.cpp


search_method.o:search_method.cpp search.h display.h
	g++ -c search_method.cpp

search_type.o:search_type.cpp search.h display.h
	g++ -c search_type.cpp

selection_menu.o:selection_menu.cpp selection.h 
	g++ -c selection_menu.cpp

selection_search.o:selection_search.cpp selection.h 
	g++ -c selection_search.cpp

update_list.o:update_list.cpp function.h search.h display.h
	g++ -c update_list.cpp

main:main.o add_record.o delete_element.o display.o analysis.o budget.o display_search.o grow_accountlist.o load_accountlist.o print_accountlist.o save_accountlist.o search_amount.o search_date.o search_method.o search_type.o selection_menu.o selection_search.o update_list.o
	g++ main.o add_record.o delete_element.o display.o analysis.o budget.o display_search.o grow_accountlist.o load_accountlist.o print_accountlist.o save_accountlist.o search_amount.o search_date.o search_method.o search_type.o selection_menu.o selection_search.o update_list.o -o main

run:main
	./main
