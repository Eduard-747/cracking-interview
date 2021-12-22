#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
class arrays {
public:
    static int solution(std::vector<int> a) {
        std::vector<int> indvec;
        std::set<int> s ;
        bool flag {false} ;
        for(int i = 0 ; i < a.size() ; ++i)
        {
            if(s.find(a[i]) != s.end()) {
                indvec.push_back(i) ;
                flag = true ;
            } else {
                s.insert(a[i]) ;
            }
        }
        return flag ? a[*std::min_element(indvec.begin(),indvec.end())] : -1 ;
    }

    static std::vector<std::vector<int>> solution(std::vector<std::vector<int>> a) {
        std::vector<std::vector<int>> tmp(a.size());
        for(int i = 0; i < a.size(); ++i) {
            tmp[i].resize(a.size()) ;
        }
        for(int i = 0; i < a.size(); ++i) {
            for(int j = 0; j < a.size(); ++j) {
                tmp[j][a.size() - i - 1] = a[i][j] ;
            }
        }
        return tmp ;
    }

    static bool solution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {

        bool flag = true ;   
        for(int i = 0 ; i < crypt.size() ; ++i)
        {
            std::find_if(solution.begin(),solution.end(),[&](std::vector<char> vec){
                if(crypt[i][0] == vec[0] && vec[1] == '0' && crypt[i].size() != 1)
                {
                    flag = false ;
                    return true ;
                } return false ;
            }) ;
        }
        
        int numberA = 0;
        for (int i = 0; i < crypt[0].size(); i++) 
        {
            std::find_if(solution.begin(),solution.end(),[&](std::vector<char> vec){
                if(crypt[0][i] == vec[0])
                {
                    numberA = numberA * 10 + vec[1] - 48 ;
                    return true ;
                } return false ;
            }) ;
        }
        int numberB = 0;
        for (int i = 0; i < crypt[1].size(); i++) 
        {
            std::find_if(solution.begin(),solution.end(),[&](std::vector<char> vec){
                if(crypt[1][i] == vec[0])
                {
                    numberB = numberB * 10 + vec[1] - 48 ;
                    return true ;
                } return false ;
            }) ;
        }
        int numberC = 0;
        for (int i = 0; i < crypt[2].size(); i++) 
        {
            std::find_if(solution.begin(),solution.end(),[&](std::vector<char> vec){
                if(crypt[2][i] == vec[0])
                {
                    numberC = numberC * 10 + vec[1] - 48 ;
                    return true ;
                } return false ;
            }) ;
        }
        std::cout << numberA << " " << numberB << " " << numberC << "\n" ;
        return ((numberA + numberB) == numberC) && flag ? true : false ;    
    }

    static char solution(std::string s) {
        for(int i = 0; i < s.size(); i++){
            char c = s[i] ;
            s[i] = '0' ;
            if(std::find(s.begin(),s.end(),c) == s.end()) 
                return c;
            else s[i] = c;
        }
        return  '_' ;
    }

    static bool check(std::string &str)
    {
        str.erase(std::remove(str.begin(),str.end(),'.'),str.end()) ;
        for(int i = 0; i < str.size(); i++){
            char c = str[i] ;
            str[i] = 'x' ;
            if(std::find(str.begin(),str.end(),c) != str.end()) 
                return false ;
            else str[i] = c;
        }
        return true ;
    }

    static bool solution(std::vector<std::vector<char>> grid) {
        std::string str ;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                str.push_back(grid[i % 3 * 3 + j % 3][i / 3 * 3 + j / 3]) ; 
            }
            if(!check(str)) return false;
            str.clear() ;
        }
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                str.push_back(grid[i][j]) ; 
            }
            if(!check(str)) return false;
            str.clear() ;
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                str.push_back(grid[j][i]) ; 
            }
            if(!check(str)) return false ;
            str.clear() ;
        }
        return true ;
    }
} ;
