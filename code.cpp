int sizeOfList(ListNode *L)
{
    int size = 0;
    
    ListNode *temp = L ;
    while( temp->next != NULL){
            size++;
           // cout << "temp->val: " << temp->val << endl;
            temp = temp->next;
    }
    
    //size is initialized with zero & last iteration we are not incrementing the size.
    size=size+1;
    
    //resetting the temp to NULL.
    temp = NULL;
    
    return size;
}


int power(int val,int exponent)
{
    int result=1;
    for(int i=0;i<exponent;i++){
        result = result * val;
    }
    
    return result;
}

int digitToNumber(ListNode *L , int size)
{
    unsigned long int number=0;
    
    for(int i=0;i<size;i++){
        number = number + ( (L->val) * power(10,i) );
        //number = number + ( (L->val) * pow(10,i) );
        //cout << "number:" << number << endl; 
        
        //move to next pointer:
        L = L->next;
    }
    
    return number;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        int firstNumber = 0;
        int secondNumber =0;
        int sum =0;
        
        int size1 = 0;
        int size2 = 0;
        
        //find the size of the linked list l1:
        size1 = sizeOfList(l1);
        size2 = sizeOfList(l2);
        
        firstNumber = digitToNumber(l1,size1);
        secondNumber = digitToNumber(l2,size2);
        
        sum = firstNumber + secondNumber;
        
        //cout << "size1:  " << size1  << endl;
        //cout << "size2:  " << size2  << endl;
        //cout << "firstNumber : " << firstNumber << endl ;
        //cout << "secondNumber: " << secondNumber << endl ;
        //cout << "sum: " << sum << endl ;
        
        //Length of sum
        int lengthOfSum =0;
        int tempsum = sum;
        while ( tempsum/10 > 0 ){
            lengthOfSum ++;
            
            tempsum = tempsum/10;
        }
        //To consider the last digit increment lengthOfSum by 1.
        lengthOfSum ++;
 
        
        
        //New node
        ListNode *currentNode = NULL ; //Next Node
        ListNode *head = NULL;
       
        
        //loop until total number of digits are covered. 
        //while ( sum/10 > 0 ){
        for(int i=0;i<lengthOfSum;i++){
            
           if(head ==NULL ){
                head = new ListNode(sum%10,NULL);
                currentNode = head ;  
           }
            else{
                currentNode->next = new ListNode(sum%10,NULL);
                currentNode = currentNode->next ;
            }
           //cout << "sum%10: " << sum%10 << endl;     

            
            sum = sum/10;
        }// for loop closed.
        
        
        return head;
        
    }
};


