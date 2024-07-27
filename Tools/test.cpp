 string replaceWords(vector<string>& dictionary, string sent) {
        sort(dictionary.begin(),dictionary.end());
        vector<string>sentence;

	    string word;
	    stringstream ss(sent);
	    while (getline(ss, word, ' ')) {
		sentence.push_back(word);
	    }

        map<char,pair<int,int>>mp;
        int n=2;
        string s=dictionary[0];
        mp[s[0]].first=1;
        for(int i=1;i<dictionary.size();i++)
        {
            string str1=dictionary[i];
            string str2=dictionary[i-1];
            if(mp[str1[0]].first==0)
            {
                 mp[str1[0]].first=n;
                 mp[str2[0]].second=n-1;
            }
            n++;
        }
        for(int i=0;i<sentence.size();i++)
        {
            string str=sentence[i];
            int l=mp[str[0]].first;
            int r=mp[str[0]].second;
            for(int j=l-1;j>0,j<r;j++)
            {
                int n1=dictionary[j].size();
                if(n1<=str.size())
                {
                    if(dictionary[j]==str.substr(0,n1)) 
                    {
                         sentence[i]=dictionary[j];
                    }
                }
                
            }
            
        }
        string answer="";
        for(int q=0;q<sentence.size();q++)
        {
            answer=answer+' '+sentence[q];
        }
        return answer;

    }