// Name: Edgar Martinez 
// Email: edgarmar@usc.edu
// Course: EE 355
// Date: 1-27-19

#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

using namespace std; 

class pancake {
	
	public:
	
	int size; 
	bool burnt; 

	// burnt == 1 means that the top side is burnt 
	void flip_pancake() {

		if(burnt == 1) {
			burnt = 0; 
		}

		else {
			burnt = 1; 
		}
	}

};

class pancake_pile {

	public:

	int Z; 
	// 7
	pancake individual_pile[100]; 

	// have the pancakes facing down in the pile 
	void pancake_burnt_down(int z) {
		
		for(int i = 0; i < z; i++) {
			
			if(individual_pile[i].burnt == 1) {
				individual_pile[i].burnt = 0; 
			}
		}
	}

	// have the pancakes facing up in the pile
	void pancake_burnt_up(int z) {
		
		for(int i = 0; i < z; i++) {
			
			if(individual_pile[i].burnt == 0) {
				individual_pile[i].burnt = 1; 
			}
		}
	}

};

class m_pancake_piles {

	public:
// 56
	pancake_pile pile_cordinate[100][100];

	void rearrange_interior(int x, int y, int z) {
		
		for(int i = 0; i < x; i++) {
		
			for(int j = 0; j < y; j++) {
			
				if(i == 0 || i == x-1) {
					// do nothing
				}
				else {
					if(j == 0 || j == y-1) {
						// do nothing
					}
					else {
						pile_cordinate[i][j].pancake_burnt_down(z);
					}
				}
			}
		}

	}	

	void rearrange_exterior(int x, int y, int z) {
		
		for(int i = 0; i < x; i++) {
			
			for(int j = 0; j < y; j++) {
				
				if(i == 0 || i == x-1) {
					pile_cordinate[i][j].pancake_burnt_up(z);
				}
				else {
					if(j == 0 || j == y-1) {
						pile_cordinate[i][j].pancake_burnt_up(z);
					}
				}
			}
		}

	}

};

int main()
{
	 
	// open the file to read from
	ifstream in_file;
	in_file.open("input.txt");
	//in_file.open("test.txt");

	int X, Y, Z;
	int size[500]; 
	bool burnt[500];

	int integer_burnt[500]; 
	string temp_X, temp_Y, temp_Z;
	string temp_size[500];
	string temp_burnt[500];	
	string line;
	
	// flag is used to read the first line in the file, since it doesn't
	// follow the same format as the rest of the file. 
	int flag = 0;

	// loop is used to index the temp array's 
	int loop = 0; 

	while(getline(in_file, line)) {

		stringstream ss(line);

		if(flag == 0) {
			getline(ss, temp_X, ' ');
			getline(ss, temp_Y, ' ');
			getline(ss, temp_Z, ' ');
			
			// cast the temp_ variables to int
			X = atoi(temp_X.c_str());
			Y = atoi(temp_Y.c_str());
			Z = atoi(temp_Z.c_str());

//			X = stoi(temp_X); 
//			Y = stoi(temp_Y);
//			Z = stoi(temp_Z);
			flag++;
		}
		else {
			for(int j = 0; j < Z; j++) {

				getline(ss, temp_size[j+loop], ',');
				// cast to int and store 
//				size[j+loop] = stoi(temp_size[j+loop]); 
				size[j+loop] = atoi(temp_size[j+loop].c_str());	
					
				getline(ss, temp_burnt[j+loop], ' ');
				if(temp_burnt[j+loop] == "1") {
					burnt[j+loop] = 1;
				}
				else if(temp_burnt[j+loop] == "0") {
					burnt[j+loop] = 0;
				}	
				
			}

		loop = loop + Y + 1; 
		}
	}

	in_file.close();

	// by now we have read all the contnents of the file and have stored the pancake sizes 
	// in size[] and burnt side of the pancakes in burnt[]	

	loop = 0;
	m_pancake_piles my_piles; 

	// start putting the pancakes into m_pancake_piles -> pancake_pile[][] -> pancake[]
	for(int i = 0; i < X; i++) {

		for(int j = 0; j < Y; j++) {
			
			for(int k = 0; k < Z; k++) {
				my_piles.pile_cordinate[i][j].individual_pile[k].size = size[k+loop]; 
				my_piles.pile_cordinate[i][j].individual_pile[k].burnt = burnt[k+loop];
			}
		
			loop = loop + Y + 1;
		}
	}
	

	my_piles.rearrange_exterior(X,Y,Z); 
	my_piles.rearrange_interior(X,Y,Z);

	// open the file to write to 
	ofstream output_file;
	output_file.open("output.txt"); 
	flag = 0; 

	for(int i = 0; i < X; i++) {
		
		for(int j = 0; j < Y; j++) {
		
			if(flag == 0) {
				output_file << X << " " << Y << " " << Z << endl;
				flag++;
			}

			for(int k = 0; k < Z; k++) {
				if(k == Z-1) {
					output_file << my_piles.pile_cordinate[i][j].individual_pile[k].size << ",";
					output_file << my_piles.pile_cordinate[i][j].individual_pile[k].burnt << " " << endl; 
				}
				else {
					output_file << my_piles.pile_cordinate[i][j].individual_pile[k].size << ",";
					output_file << my_piles.pile_cordinate[i][j].individual_pile[k].burnt << " ";
				}
			}
		}

	}	
		
	output_file.close(); 

	return 0; 
}

