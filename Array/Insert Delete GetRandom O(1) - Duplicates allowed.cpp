RandomizedCollection is a data structure that contains a collection of numbers, possibly duplicates (i.e., a multiset). It should support inserting and removing specific elements and also reporting a random element.

Implement the RandomizedCollection class:

 --RandomizedCollection() Initializes the empty RandomizedCollection object.

 --bool insert(int val) Inserts an item val into the multiset, even if the item is already present. Returns true if the item is
   not present, false otherwise.

 --bool remove(int val) Removes an item val from the multiset if present. Returns true if the item is present, false otherwise.
   Note that if val has multiple occurrences in the multiset, we only remove one of them.

 --int getRandom() Returns a random element from the current multiset of elements. The probability of each element being 
   returned is linearly related to the number of the same values the multiset contains.

You must implement the functions of the class such that each function works on average O(1) time complexity.

Note: The test cases are generated such that getRandom will only be called if there is at least one item in the 
RandomizedCollection.

 

Example 1:

Input
["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
[[], [1], [1], [2], [], [1], []]
Output
[null, true, false, true, 2, true, 1]

Explanation
RandomizedCollection randomizedCollection = new RandomizedCollection();
randomizedCollection.insert(1);   // return true since the collection does not contain 1.
                                  // Inserts 1 into the collection.
randomizedCollection.insert(1);   // return false since the collection contains 1.
                                  // Inserts another 1 into the collection. Collection now contains [1,1].
randomizedCollection.insert(2);   // return true since the collection does not contain 2.
                                  // Inserts 2 into the collection. Collection now contains [1,1,2].
randomizedCollection.getRandom(); // getRandom should:
                                  // - return 1 with probability 2/3, or
                                  // - return 2 with probability 1/3.
randomizedCollection.remove(1);   // return true since the collection contains 1.
                                  // Removes 1 from the collection. Collection now contains [1,2].
randomizedCollection.getRandom(); // getRandom should return 1 or 2, both equally likely.
 

Constraints:

-231 <= val <= 231 - 1
At most 2 * 105 calls in total will be made to insert, remove, and getRandom.
There will be at least one element in the data structure when getRandom is called.



"Hard problem and answer is difficult to understand"

--There are two data member in the solution--

a vector nums
an unordered_map m
The key of m is the val, the value of m is a vector contains indices where the val appears in nums.
Each element of nums is a pair, the first element of the pair is val itself, the second element of the pair is the 
 index ofm[val].
There is a relationship between nums and m:

m[nums[i].first][nums[i].second] == i;



Lets take the input as Input: [5,7,3,7,5]

Hashmap contains the numbers and their indices in an array i.e 5 -> [0,4]
Nums contain a pair which represents: {num, index_in_hashmap}.

After insertion the hashmap would be:-
3 : 2
7 : 1, 3
5 : 0, 4

And nums would be:
[<5,0> , <7,0>, <3,0>, <7,1>, <5,1>]


--- inserting and getRandom functions look straightforward.
--- in deletion basic (idea is to place the last item in place of element to be deleted and delete the last item)

--- steps in deleting 
 1. update the position of last item in nums to position of item going to get deleted
    auto last = nums.back();
    mpp[last.first][last.second] = mpp[val].back();

 2. now set num[index going to get deleted] to last item in nums
    nums[mpp[val].back()] = last;

 3. remove last element from nums and mpp[val] 
    nums.pop_back();
    mpp[val].pop_back();

 4. if nums[val] is empty erase it 




'example'
Lets say we want to remove 7.
Get details for last pair in nums.

auto last = nums.back();
int key = last.first;
int last_index = last.second;
The statement below updates the index last item in the array to the index of the val.
m[last.first][last.second]

Update the value of the index in the last pair of nums. This value needs to replaced with the index where val is currently
(why? because we are moving the last pair in nums to where val in nums is. Why? We need this because we will be getting 
rid of this last pair in nums and before we get rid of it we need to move it to val’s position).

This changes 5-> 0,4 to 5->0,3. Which basically says that <5,1> now resides at index 3 instead of 4. 
(but hey we didnt actually move <5,1> yet we do this right after this)
m[last.first][last.second] = m[val].back()

This will move <5,1> from last position to the place where <7,1> is located.
nums[m[val].back()] = last

This will remove the last index of val ( it will remove 3 from the array of 7. Basically saying <7,1> is no longer part of nums)
m[val].pop_back()

Remove the last item from the vector
nums.pop_back()

Edge case
If all the indexes of a val are removed then also remove the key.





CODE ::::


class RandomizedCollection {
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        auto res = mpp.find(val) == mpp.end();

        mpp[val].push_back(nums.size());
        nums.push_back({val,mpp[val].size() - 1});
        return res;
    }
    
    bool remove(int val) {
        auto res = mpp.find(val) != mpp.end();
        if(res){
            auto last = nums.back();
            mpp[last.first][last.second] = mpp[val].back();
            nums[mpp[val].back()] = last;

            nums.pop_back();
            mpp[val].pop_back();
            if(mpp[val].empty()){
                mpp.erase(val);
            }
        }
        return res;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
    private :
    unordered_map<int,vector<int>> mpp;
    vector<pair<int,int>> nums;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */