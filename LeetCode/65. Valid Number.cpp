class Solution {
public:
    bool is_dig(char c){
        return c>='0'&&c<='9';
    }
    bool is_char(char c){
        return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
    }

    bool isNumber(string s) {
        int p=0,c=0,v=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='E'||s[i]=='e'){
                p=1,c++;
                if(!(i+1!=s.size()&&i))return 0;
            }

            if(s[i]=='.'){
                v++;
                if(p||(!i||!is_dig(s[i-1]))&&(i+1==s.size()||!is_dig(s[i+1])))return 0;
            }

            if(s[i]=='+'||s[i]=='-'){
                if(!(!i||s[i-1]=='E'||s[i-1]=='e')||i+1==s.size()||(!is_dig(s[i+1])&&s[i+1]!='.'))return 0;
                
            }

            if(s[i]!='E'&&s[i]!='e'&&is_char(s[i]))return 0;
        }

        return (c<2&&v<2);
    }
};