#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <conio.h>

using namespace std;
char alphainlower[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int incorrectArrangement(string input)
{
    string line;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while(getline(words,line))
        {
            string Ainput = input, Binput, permutation, Cinput, Cline, Bline, Aline = line;
            int lngth = Ainput.size(), zlen = line.size();
            if (lngth == zlen)
            {
                for (int i=1; i<Ainput.length(); i++)
                    Binput.push_back(input[i]);
                for (int i = 1; i < zlen; i++)
                    Bline.push_back(Aline[i]);
                Ainput.resize(1);
                Aline.resize(1);
                sort(Bline.begin(),Bline.end());
                sort(Binput.begin(), Binput.end());
                Cinput = Ainput + Binput;
                Cline = Aline + Bline;
                if (Cinput == Cline)
                {
                    found = 1;
                    cout<<line<<endl;
                    break;
                }
            }
        }
        words.close();
    }
    else
    {
        cout<<endl<<"Unexpected error occurred......."<<endl;
    }
    return found;
}

int characters_exchanged (string input)
{
    string line, Ainput;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            int lngth = input.size(), zlen = line.size();
            if (lngth == zlen)
            {
                for (int i = lngth-1; i >= 0 ; i--)
                {
                    Ainput = input;
                    Ainput[i] = alphainlower[0];
                    for (int j=0; j<26; j++)
                    {
                        if (Ainput == line)
                        {
                            found = 1;
                            cout<<line<<endl;
                            break;
                        }
                        Ainput[i] =alphainlower[j];
                    }
                    if (found == 1 ) break;
                    else continue;
                }
            }
        }
        words.close();
    }
    else cout<<"\nUnexpected error occurred"<<endl;
    return found;
}
int character_missing (string input)
{
    string Ainput, line, Cinput, Cline, Aline;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            for (int i = 0; i < 26; i++)
            {
                int lngth = input.size(), zlen = line.size();
                Ainput = input;
                Aline = line;
                Ainput.resize(lngth+1,'a');
                Ainput[lngth] = alphainlower[i];
                lngth = Ainput.size();
                string Binput, Bline;
                if (lngth == zlen)
                {
                    for (int j = 1; j <=lngth; j++)
                        Binput.push_back(Ainput[j]);
                    for (int j = 1; j <= zlen; j++)
                        Bline.push_back(Aline[j]);
                    Ainput.resize(1);
                    Aline.resize(1);
                    sort(Bline.begin(),Bline.end());
                    sort(Binput.begin(),Binput.end());
                    Cinput = Ainput + Binput;
                    Cline = Aline + Bline;
                    if (Cinput == Cline)
                    {
                        found = 1;
                        cout<<line<<endl;
                        break;
                    }
                }
                if (found == 1) break;
            }
            if (found == 1) break;
        }
        words.close();
    }
    else
    {
        cout<<"\nUnexpected error occurred\n";
    }
    return found;
}

int character_extra (string input)
{
    string Ainput, line, Binput, Cinput;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
             int lngth = input.size(), zlen = line.size();
             if ((lngth-1) == zlen)
             {
                 for (int i = 1; i < lngth; i++)
                 {
                     Ainput = input;
                     Ainput.erase(Ainput.begin()+i);
                     if (Ainput == line)
                     {
                         found = 1;
                         cout<<line<<endl;
                         break;
                     }

                 }
             }
        }
        words.close();
    }
    else
    {
        cout<<"\nUnexpected error occurred\n";
    }
    return found;
}

int extra_mixed_missing (string input)
{
    string Ainput, line, Aline;
    int found = 0;
    ifstream words ("words.txt");
    if (words)
    {
        while (getline(words,line))
        {
            int lngth = input.size(), zlen = line.size();
            if (lngth == zlen)
            {
                for (int i = 1; i < lngth; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        Ainput = input; Aline = line;
                        Ainput.erase(Ainput.begin()+i);
                        Ainput.resize(lngth, 'a');
                        Ainput[lngth-1] = alphainlower[j];
                        sort(Ainput.begin()+1,Ainput.end());
                        sort(Aline.begin()+1,Aline.end());
                        if (Ainput == Aline)
                        {
                            found = 1;
                            cout<<line<<endl;
                            break;
                        }
                    }
                    if (found == 1) break;
                }
                if (found == 1) break;
            }
        }
        words.close();
    }
    return found;
}

int main()
{
    while (1) {
        string input,line;
        int lngth,zlen,crct=0;
        cout<<"Enter the word: "; getline(cin,input);
        lngth = input.length();
        for (int i=0; i < lngth; i++)
            input[i] = tolower(input[i]);
        ifstream words ("words.txt");
        if(words)
        {
            while (getline(words,line))
            {
                zlen = line.length();
                if (lngth==zlen)
                {
                    if (line==input)
                    {
                        crct=1;
                    }
                    else continue;
                }
                else continue;
            }
            words.close();
            if (crct==1)
            {
                cout<<endl<<"~~~~~~~~Correct Spelling~~~~~~~~"<<endl;
            }
            if (crct==0)
            {
                int miss = 0, ex = 0, mix = 0, incorrect = 0, exchange = 0;
                cout<<endl<<"Spelling is wrong. Possible right spellings are given below:- "<<endl<<endl;
                miss = character_missing(input);
                ex = character_extra(input);
                mix = extra_mixed_missing(input);
                incorrect = incorrectArrangement(input);
                exchange = characters_exchanged(input);
                if (miss == 0 && ex == 0 && mix == 0 && incorrect == 0 && exchange == 0)
                {
                    cout<<endl<<"No such word exist"<<endl;
                }
            }
        }
        else
        {
            cout<<"Not able to open words.txt"<<endl;
        }
        cout<<endl<<"Press any key to continue..."<<endl<<endl;
        _getch();
    }
    return 0;

}
