class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> ph = Arrays.asList("abc","def","ghi","jkl","mno","pqrs","tuv","wxyz");
        List<String> answer = new ArrayList<>();
        if(digits.equals("")) return answer;
        cons(digits, 0, ph, "", answer);
        return answer;
    }

    private void cons(String digits, int i, List<String> ph, String s, List<String> answer){
        if(i==digits.length()){
            answer.add(s);
            return;
        }
        int number = digits.charAt(i) - '0'-2;
        for(int j = 0;j<ph.get(number).length();j++){
            cons(digits, i+1, ph, s+ph.get(number).charAt(j),answer);
        }
    } 
    }
