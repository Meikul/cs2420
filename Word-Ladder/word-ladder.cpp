#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Step
{
    Step(string w, Step* p)
    {
        word = w;
        parent = p;
    }
    string word;
    Step * parent;
};

vector <Step> offByOne(Step& parent, vector <string>& dict)
{
    vector <Step> oboWords;
    for (unsigned int i=0; i < dict.size(); i++)
    {
        unsigned int offBy = 0;
        for (unsigned int j=0; j < parent.word.length(); j++)
        {
            if(parent.word[j] != dict[i][j]) offBy++;
        }
        Step toPush(dict[i], &parent);
        if (offBy == 1) oboWords.push_back(toPush);
    }
    return oboWords;
}

Step* isEnd(vector <Step>& group, string endWord)
{
    for(unsigned int i=0; i < group.size(); i++)
    {
        if(group[i].word == endWord) return &group[i];
    }
    return nullptr;
}

void display(Step* step)
{
    cout << step->word << endl;
    if(step -> parent) display(step->parent);
    return;
}

int main()
{
    ifstream dictFile;
    dictFile.open("dictionary.txt");
    if(!dictFile)
    {
        cout << "Trouble opening file" << endl;
        return 0;
    }
    
    vector <string> fullDict;
    string word;
    while(dictFile >> word)
    {
        fullDict.push_back(word);
    }
    
    string startWord = "start";
    string endWord = "gnarl";
    if (startWord.length() != endWord.length())
    {
        cout << "Words aren't the same length." << endl;
        return 0;
    }
    if(startWord == endWord)
    {
        cout << startWord << endl;
        return 0;
    }
    
    vector <string> dict;
    for (unsigned int i=0; i < fullDict.size(); i++)
    {
        if(fullDict[i].length() == startWord.length())
        {
            dict.push_back(fullDict[i]);
            // cout << fullDict[i] << endl;
        }
    }
    
    Step start(startWord, nullptr);
    vector <Step> group = offByOne(start, dict);
    while(!isEnd(group, endWord))
    {
        vector <Step> oldGroup = group;
        group.clear();
        for(unsigned int i=0; i < oldGroup.size(); i++)
        {
            cout << oldGroup[i].word << endl;
            vector <Step> oboWords = offByOne(oldGroup[i], dict);
            group.insert(group.end(), oboWords.begin(), oboWords.end());
        }
    }
    display(isEnd(group, endWord));
    
    return 0;
}
