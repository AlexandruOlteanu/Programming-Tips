The idea of lazily deleting elements is a salient one, but by putting in a bit more effort when inserting an element into the window we can get amortized O(1) run-time. 
Say our window contains the elements {1, 6, 7, 2, 4, 2}. We want to add the element 5 to our window. Notice that all elements in the window greater than 5 will now never 
be the minimum in the window for future i values, so we might as well get rid of them. The trick to this is to store the numbers in a deque [1] and whenever inserting a 
number x we remove all numbers at the back of the deque which are greater than equal to x. Notice that if the deque was sorted before inserting, it will still be sorted 
after inserting x. Since the deque starts off sorted, it remains sorted throughout the sliding window algorithm. So the front of the deque will always be the smallest value.

The front of the queue might have a value which shouldn't be in the window anymore, but we can use the lazy delete idea with the deques as well. Now each element of ARR is 
inserted into the deque and deleted from the deque at most once. This gives as a total run-time of O(N) for the algorithm (amortized O(1) per insertion/deletion). Pretty 
sweet:

void sliding_window_minimum(std::vector<int> & ARR, int K) {
  // pair<int, int> represents the pair (ARR[i], i)
  std::deque< std::pair<int, int> > window;
  for (int i = 0; i < ARR.size(); i++) {
     while (!window.empty() && window.back().first >= ARR[i])
       window.pop_back();
     window.push_back(std::make_pair(ARR[i], i));

     while(window.front().second <= i - K)
       window.pop_front();

     std::cout << (window.front().first) << ' ';
  }
}

  For maximum Element in a window we just change from >= to <=
  
  Related Problem : https://codeforces.com/contest/373/problem/E
