#include <vector>

using namespace std;


vector <int> merge_unique(vector <int> left, vector <int> right){
    vector <int> result;
    int last, curr;
    vector <int>::iterator l_it = left.begin(), l_end = left.end(), 
            r_it = right.begin(), r_end = right.end();

    while(l_it != l_end and r_it != r_end){
        if(*l_it <= *r_it){
            curr = *l_it;
            ++l_it;
        } else {
            curr = *r_it;
            ++r_it;
        }

        if(not result.empty() and last == curr){
            continue;
        }

        result.push_back(curr);
        last = curr;
    }

    while(l_it != l_end){
        curr = *l_it;
        ++l_it;
        if(not result.empty() and last == curr){
            continue;
        }

        result.push_back(curr);
        last = curr;
    }
    

    while(r_it != r_end){
        curr = *r_it;
        ++r_it;
        if(not result.empty() and last == curr){
            continue;
        }

        result.push_back(curr);
        last = curr;
    }

    return result;
}


vector <int> mergesort_unique(vector <int>::iterator left, vector <int>::iterator right){
    if(right - left == 1){
        return vector <int>(left, right);  // TODO: unique for small vectors
    } else {
        vector <int>::iterator middle = left + (right - left) / 2;
        vector <int> left_v = mergesort_unique(left, middle), right_v = mergesort_unique(middle, right);
        return merge_unique(left_v, right_v);
    }
}


vector <int> removeDuplicates(vector <int> input){
    return mergesort_unique(input.begin(), input.end());
}