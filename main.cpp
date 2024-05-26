#include "simple.h"
#include "flag.h"

using std::pair;

void greetings() //func that just returns information about author and work
{
    cout << "\nBohdan Petrov, K13, Lab_05, var_34\n\n";
    cout << "Press Enter to Continue...";
    char temp1; while(temp1 != '\n') std::cin.get(temp1);

    cout << "\nWrite sequence in output.txt file with special subsequences(spiral, snake)\n\n";
    cout << "Press Enter to Continue...";
    char temp2; while(temp2 != '\n') std::cin.get(temp2);
}

void farewell()
{
  cout << "Program terminates, no problem found. Bye\n";
}

int main(int argc, char* argv[])
{
    greetings(); // greeting message
    string IN, OUT;
    if(!get_args(argc, argv, IN, OUT)) //checking argc
    {
      help_flag(); // writing help message if something wrong with arguments 
      return 0;   
    }
    ifstream Input(IN); //opening in.txt
    ofstream Output(OUT, std::ofstream::out | std::ofstream::trunc); //opening out.txt
    try{
    Matrix input_maxtrix(Input); //constructing Matrix (see simple.cpp/simple.h) from given txt file
  
    pair<vector<int>, vector<int> > sequence{first(input_maxtrix),second(input_maxtrix)};
    for(auto&it: sequence.first)
    {
      Output << it << " ";
    }
     for(auto&it: sequence.second)
    {
      Output << it << " ";
    }
    }
    catch(const std::invalid_argument& ia){
      Input.close();
      Output.close();
      std::cerr << "Invalid argument: " << ia.what() << '\n';
      return 0;
    }
    Input.close(); //closing txt
    Output.close(); // closing txt
    farewell(); // goodbye message
    
    return 1;
 }


