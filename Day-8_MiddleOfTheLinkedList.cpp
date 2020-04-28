struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* createList(vector<int> &v){
    ListNode *head = NULL, *temp=NULL;
    for(auto x : v){
        if(head == NULL){
            head = new ListNode(x);
            temp = head;
        }
        else{
            temp->next = new ListNode(x);
            temp = temp->next;
        }
    }
    return head;
}

void PrintListFrom(ListNode *start){
    while (start!=NULL) {
        cout<<start->val<<" ";
        start = start->next;
    }
}

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *temp=head;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        //cout<<"length = "<<count<<"\n";
        float mid=count/2.0;
        if(mid==(int)mid) mid++;
        else mid=(int)(mid+1);
        //cout<<"mid = "<<mid<<"\n";
        count = 0;
        temp=head;
        while(temp->next!=NULL){
            count++;
            if(count==mid) return temp;
            temp=temp->next;
        }
        return temp;
    }
};

//driver code
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    ListNode *head = NULL;
    vector<int> v = {1,2,3,4,5,6};
    head = createList(v);
    ListNode * middle_node;
    middle_node = s.middleNode(head);
    PrintListFrom(middle_node);
    return 0;
}

