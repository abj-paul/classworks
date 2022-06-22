#include<bits/stdc++.h>
using namespace std;

#define Z 'Z'
#define CAN_NOT_POP -1
int q0=0, q1=1, qf=2;
int EMPTY_STACK_BUT_STRING_REMAINS=100;
stack<int>pda_stack;

//https://scanftree.com/automata/npda-for-ww-to-power-R

int push_delta(int current_state, char alphabet, char stack_top){
        if(current_state==q0 && alphabet=='a' && stack_top==Z){
            printf("push_delta(%d,%c,%c)\n",current_state, alphabet, stack_top);
            pda_stack.push(alphabet);
            return q0;
        }else if(current_state==q0 && alphabet=='a' && stack_top=='a'){
            printf("push_delta(%d,%c,%c)\n",current_state, alphabet, stack_top);
            pda_stack.push(alphabet);
            return q0;
        }else if(current_state==q0 && alphabet=='b' && stack_top==Z){
            printf("push_delta(%d,%c,%c)\n",current_state, alphabet, stack_top);
            pda_stack.push(alphabet);
            return q0;
        }else if(current_state==q0 && alphabet=='b' && stack_top=='b'){
            printf("push_delta(%d,%c,%c)\n",current_state, alphabet, stack_top);
            pda_stack.push(alphabet);
            return q0;
        }else if(current_state==q0 && alphabet=='a' && stack_top=='b'){
            printf("push_delta(%d,%c,%c)\n",current_state, alphabet, stack_top);
            pda_stack.push(alphabet);
            return q0;
        }else if(current_state==q0 && alphabet=='b' && stack_top=='a'){
            printf("push_delta(%d,%c,%c)\n",current_state, alphabet, stack_top);
            pda_stack.push(alphabet);
            return q0;
        }else{
            printf("Unknown Push_Delta command!\n");
            exit(1);
        }
}

int pop_delta(int current_state, char alphabet, char stack_top){
    if(current_state==q0 && alphabet=='a' && stack_top=='a'){
        printf("pop_delta(%d,%c,%c)\n",current_state, alphabet, stack_top);
        pda_stack.pop();
        return q1;
    }else if(current_state==q0 && alphabet=='b' && stack_top=='b'){
        printf("pop_delta(%d,%c,%c)\n",current_state, alphabet, stack_top);
        pda_stack.pop();
        return q1;
    }

    else if(current_state==q1 && alphabet=='b' && stack_top=='b'){
        printf("pop_delta(%d,%c,%c)\n",current_state, alphabet, stack_top);
        pda_stack.pop();
        return q1;
    }else if(current_state==q1 && alphabet=='a' && stack_top=='a'){
        printf("pop_delta(%d,%c,%c)\n",current_state, alphabet, stack_top);
        pda_stack.pop();
        return q1;
    }
    else if(current_state==q1 && alphabet=='\0' && stack_top==Z){
        printf("pop_delta(%d,%c,%c)\n",current_state, alphabet, stack_top);
        //pda_stack.pop();
        return qf;
    }else{
        //printf("Unknown Pop_Delta command! ");
        //printf("pop_delta(%d,%c,%c)\n",current_state, alphabet, stack_top);

        //exit(1);
        return CAN_NOT_POP;
    }
}

void clear_stack(){
    while(!pda_stack.empty()) pda_stack.pop();
}

bool npda(string input){
  bool truth_value = false;

  for(int assumed_mid_point = 0; assumed_mid_point<input.size()-1; assumed_mid_point++){
        int current_state = q0;
        clear_stack();
        pda_stack.push(Z);

	printf("Assumed mid = %d-----------------\n",assumed_mid_point);

	int i=0;
        for(i=0; i<input.size(); i++){
            if(i<=assumed_mid_point) current_state = push_delta(current_state, input[i], pda_stack.top());
            else if(i>assumed_mid_point) current_state = pop_delta(current_state, input[i], pda_stack.top());

            if(pda_stack.size()==1){
                // STACK EMPTY BUT NOT EOF
                //printf("DEBUG-01.\n");
                truth_value=false;
                break;
            }
            else if(current_state==CAN_NOT_POP){
                //printf("DEBUG-02.\n");
                truth_value=false;
                break;
            }
        }
        current_state = pop_delta(current_state, '\0', pda_stack.top());
        if(current_state==qf && i==input.size()-1) return true;
  }
  return truth_value;
}

int main(){
    string input;
    cin>>input;
    cout<<npda(input)<<endl;
return 0;
}
