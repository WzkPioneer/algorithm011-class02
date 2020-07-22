class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset{wordList.begin(),wordList.end()}; //处理endWord不在wordList中的特殊情况
        if(wordset.find(endWord) == wordset.end()) return 0;
        unordered_set<string> begintoend{beginWord}; //用来存放从起点开始，匹配到的单词
        unordered_set<string> endtobegin{endWord};//用来存放从终点开始，匹配到的单词

        queue<string> beginQ; //从起点开始，可能的单词入队
        queue<string> endQ; //从终点开始，可能的单词入队
        beginQ.push(beginWord);
        endQ.push(endWord);

        int depth = 0;

        while(!beginQ.empty()&&!endQ.empty()){  //任何一个队列为空，都是线索断了的意思，所以要用&&
            int flag_begintoend = 1;
            if(beginQ.size() > endQ.size()){ //这里选择一个较短的队列进行搜索
                swap(beginQ,endQ); //交换的意义在于，后面代码我们只准备用一个队列变量来进行搜索，所以要把较短的队列统一到beginQ上，便于后面做搜索，当然也可以重新写个bfs函数，就不需要交换了。
                flag_begintoend = 0; //flag用于判断下方代码while使用的BeginQ是真的BeginQ，还是假的BeginQ
            }else{
                flag_begintoend = 1;
            }

            int size = beginQ.size(); //当前较短队列中存放的元素个数
            depth++;
            while(size--){
                string hop = beginQ.front();
                beginQ.pop();
                for(auto & w:wordList){
                    //排除重复遍历单词
                    //当前beginQ是begintoend的路径上的元素
                    if(flag_begintoend && begintoend.find(w)!=begintoend.end()) continue;
                    //当前beginQ是endtobegin的路径上的元素
                    if(!flag_begintoend && endtobegin.find(w)!= endtobegin.end()) continue;
                    int diff = 0;
                    for(int i = 0;i<hop.size();i++){
                        if(hop[i]!=w[i]){
                            diff++;
                        }
                        if(diff > 1) break;
                    }

                    if(diff == 1){
                        //当前beginQ是begintoend的路径上的元素
                        //但是找到的新元素已经出现在了endtobegin的路径中
                        if(flag_begintoend && endtobegin.find(w)!=endtobegin.end() ) return depth+1;
                        //当前beginQ是endtobegin的路径上的元素
                        //但是找到的新元素已经出现在了begintoend的路径中
                        if(!flag_begintoend && begintoend.find(w)!=begintoend.end() ) return depth+1;

                        beginQ.push(w);

                        if(flag_begintoend ){
                            begintoend.insert(w);//记录出现在了begintoend的路径中的元素，避免重复遍历
                        }else{
                            endtobegin.insert(w);//记录出现在了endtobegin的路径中的元素，避免重复遍历
                        }
                    }
                }
            }
            //最后还是需要还原队列对应关系
            if(!flag_begintoend){
                swap(beginQ,endQ);
            }
        }
        return 0;
    }
};
