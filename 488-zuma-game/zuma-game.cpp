class Solution {
public:
    int findMinStep(string board, string hand) {
		sort(hand.begin(), hand.end()); 
        queue<string> bq; 
        queue<string> hq;
        queue<int> stepq; 
        unordered_set<string> visited; 
        visited.insert(board + "#" + hand);
        bq.push(board);
        hq.push(hand);
        stepq.push(0); 
        
        while (!hq.empty()) {
            string curBoard = bq.front();
            bq.pop();
            string curHand = hq.front();
            hq.pop();
            int curStep = stepq.front();
            stepq.pop();
			
			
            for (int i = 0; i < curBoard.length(); i++) {
                for (int j = 0; j < curHand.length(); j++) {
				
					
                    if (j > 0 && curHand[j] == curHand[j - 1]) continue;
                    if (i > 0 && curBoard[i - 1] == curHand[j]) continue;
					
                    bool worthTrying = false;
					
					
                    if (curBoard[i] == curHand[j]) worthTrying = true;
                    else if (0 < i && curBoard[i] == curBoard[i - 1]
                      && curBoard[i] != curHand[j]) worthTrying = true;
                    
                    if (worthTrying) {
                        string newBoard = updateBoard(curBoard.substr(0, i) + curHand[j] + curBoard.substr(i), i);
                        if (newBoard == "") return curStep + 1;
                        string newHand = curHand.substr(0, j) + curHand.substr(j + 1);
                        if (visited.find(newBoard + "#" + newHand) == visited.end()) {
                            bq.push(newBoard);
                            hq.push(newHand);
                            stepq.push(curStep + 1);
                            visited.insert(newBoard + "#" + newHand);
                        }
                    }
                }
            }
        }
        return -1;
    }
    
    string updateBoard(string board, int idx) {
        if (idx < 0) return board;
        int left = idx, right = idx;
        while (left > 0 && board[left] == board[left - 1]) left--;
        while (right < board.length() && board[right] == board[right + 1]) right++;
        
        int sameClrLen = right - left + 1;
        if (sameClrLen >= 3)
            return updateBoard(board.substr(0, left) + board.substr(right + 1), left - 1);
        else
            return board;
    }
};