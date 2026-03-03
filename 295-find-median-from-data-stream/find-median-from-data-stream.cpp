class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>minPq;
    priority_queue<int>maxPq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxPq.size()==0)
        {
            maxPq.push(num);
            return;
        }
        int top=maxPq.top();
        if(top<=num)
        {
            if(maxPq.size()>minPq.size())minPq.push(num);
            else
            {
                 minPq.push(num);
                int t=minPq.top();
                minPq.pop();
                maxPq.push(t);
            }
        }
        else
        {
            if(maxPq.size()>minPq.size())
            {
                int t=maxPq.top();
                maxPq.pop();
                maxPq.push(num);
                minPq.push(t);
            }
            else
            {
                maxPq.push(num);
            }
        }
    }
    
    double findMedian() {
        double ans=0;
        int s1=maxPq.size();
        int s2=minPq.size();
         int s=s1+s2;
         if((s%2)==1) ans=maxPq.top();
         else
         {
            ans=(maxPq.top()+minPq.top())/2.0;
         }
         return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */