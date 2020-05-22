NAME = a.out

FILES = Knight \
	File_Group \
	File_Owner \
	File_Size \
	find_max_gr \
	find_max_nln \
	find_max_so \
	find_max_ss \
	Name_out \
	numlenth \
	Num_links \
	Permiss \
	sort \
	strjoin \
	Time \
	Total \

SRC = $(addprefix src/, $(addsuffix .cpp,$(FILES)))

all: install
install:
	@g++ $(SRC) -o $(NAME)

uninstall: 
	@rm -rf $(NAME)
	
reinstall: uninstall install
