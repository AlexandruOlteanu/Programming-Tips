    Binary Indexed Tree also called Fenwick Tree provides a way to represent an array of numbers in an array, allowing prefix sums to be calculated 
efficiently. For example, an array [2, 3, -1, 0, 6] is given, then the prefix sum of first 3 elements [2, 3, -1] is 2 + 3 + -1 = 4. Calculating 
prefix sum efficiently is useful in various scenarios.
  
  //updates the tree by adding an element to coresponding indices
  void update(int x, int n, ll val){
    for(x = x; x <= n; x += x & -x){
        bit[x] += val;
    }
  }
  
  // returns the sum value for prefix [1, x]
  ll fenw(int x){
    ll sum = 0;
    for(x = x; x > 0; x -= x & -x){
        sum += bit[x];
    }
    return sum;
  }
  
  
    Fenwick tree can be also used in counting inversions in a permutation / array (minimum number of adjacent swaps to sort the array)!
    
    int n;
    cin>>n;
    ll mx = 0;
    for(int i = 1; i <= n; ++i){
        cin>>a[i];
        mx = max(mx, a[i]);
    }
    ll invcount = 0;
    for(int i = n; i >= 1; --i){
        invcount += fenw(a[i]);
        update(a[i], mx, 1);
     }
     cout<<invcount<<'\n';
  
  
  
