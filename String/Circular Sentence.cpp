/* Leetcode Problem No.: 2490. Circular Sentence */

/*
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/circular-sentence/description/
*/



class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence.back()!=sentence[0])    return false;

        int n=sentence.size();
        int i=0;
        while(i<n){
            while(i<n and sentence[i]!=' ')
                i+=1;
            if(i<n and sentence[i-1]!=sentence[i+1])
                return false;
            i+=1;
        }
        return true;
    }
};

/*
//JAVA
class Solution {
    public boolean isCircularSentence(String sentence) {
        if (sentence.charAt(sentence.length() - 1) != sentence.charAt(0)) {
            return false;
        }

        int n = sentence.length();
        int i = 0;
        while (i < n) {
            while (i < n && sentence.charAt(i) != ' ') {
                i++;
            }
            if (i < n && sentence.charAt(i - 1) != sentence.charAt(i + 1)) {
                return false;
            }
            i++;
        }
        return true;
    }
}

#Python
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        if sentence[-1] != sentence[0]:
            return False

        n = len(sentence)
        i = 0
        while i < n:
            while i < n and sentence[i] != ' ':
                i += 1
            if i < n and sentence[i - 1] != sentence[i + 1]:
                return False
            i += 1
        return True
