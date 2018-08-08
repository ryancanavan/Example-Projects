#include <iostream>
#include <vector>
using namespace std;

struct node{
	int value;
	char identifier; //either l for leaf or i for internal node
};

vector<node> preToPost(vector<node> pre){ //preorder to postorder
	vector<node> post;
	for (int i = 0; i < pre.size(); i++){
		if (pre[i].identifier == 'l'){
			post.push_back(pre[i]);
			post.push_back(pre[i + 1]);
			post.push_back(pre[i - 1]);
			i++;
		}
	}
	post.push_back(pre.front());
	return(post);
}

vector<node> postToPre(vector<node> post){ //postorder to preorder
	vector<node> pre;
	pre.push_back(post.back());
	for (int i = 0; i < post.size(); i++){
		if (post[i].identifier == 'i'){
			pre.push_back(post[i]);
			pre.push_back(post[i - 2]);
			pre.push_back(post[i - 1]);
			i++;
		}
	}
	return(pre);
}

vector<node> preToIn(vector<node> pre){ //preorder to inorder
	vector<node> in;
	for (int i = 0; i < pre.size(); i++){
		if (pre[i].identifier == 'l'){
			in.push_back(pre[i]);
			in.push_back(pre[i - 1]);
			in.push_back(pre[i + 1]);
			i++;
		}
	}
	in.insert(in.begin() + 3, pre.front());
	return(in);
}

int main(){
//	      1
//	     /\
//	    2  3
//	   /\  /\
//	  4  5 6 7
// Preorder: 1, 2, 4, 5, 3, 6, 7
// Postorder: 4, 5, 2, 6, 7, 3, 1
// Inorder: 4, 2, 5, 1, 6, 3, 7

	node one;
	one.identifier = 'i';
	one.value = 1;
	node two;
	two.identifier = 'i';
	two.value = 2;
	node four;
	four.identifier = 'l';
	four.value = 4;
	node five;
	five.identifier = 'l';
	five.value = 5;
	node three;
	three.identifier = 'i';
	three.value = 3;
	node six;
	six.identifier = 'l';
	six.value = 6;
	node seven;
	seven.identifier = 'l';
	seven.value = 7;

	vector<node> preorder;
	preorder.push_back(one);
	preorder.push_back(two);
	preorder.push_back(four);
	preorder.push_back(five);
	preorder.push_back(three);
	preorder.push_back(six);
	preorder.push_back(seven);
	vector<node> postorder;
	postorder.push_back(four);
	postorder.push_back(five);
	postorder.push_back(two);
	postorder.push_back(six);
	postorder.push_back(seven);
	postorder.push_back(three);
	postorder.push_back(one);
	vector<node> preToPostOutput;
	vector<node> postToPreOutput;
	vector<node> preToInOutput;
	preToPostOutput = preToPost(preorder);
	postToPreOutput = postToPre(postorder);
	preToInOutput = preToIn(preorder);

	cout << "My preorder list is: ";
	for (int i = 0; i < preorder.size(); i++)
		cout << preorder[i].value;
	cout << endl << "My postorder list is: ";
	for (int i = 0; i < postorder.size(); i++)
		cout << postorder[i].value;
	cout << endl << "My postorder list created from my preorder list is: ";
	for (int i = 0; i < preToPostOutput.size(); i++)
		cout << preToPostOutput[i].value;
	cout << endl << "My preorder list created from my postorder list is: ";
	for (int i = 0; i < postToPreOutput.size(); i++)
		cout << postToPreOutput[i].value;
	cout << endl << "My inorder list created from my preorder list is: ";
	for (int i = 0; i < preToInOutput.size(); i++)
		cout << preToInOutput[i].value;
	cout << endl;

	return 0;
}
