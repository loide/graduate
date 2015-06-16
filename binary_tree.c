#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *right_next;
	struct node *left_next;
} t_node;

t_node *create_node (int value){
	t_node *new_node;

	if ((new_node = (t_node *) malloc (sizeof (t_node))) == NULL)
		return NULL;
	else {
		new_node->value = value;
		new_node->right_next = NULL;
		new_node->left_next = NULL;
	}

	return new_node;
}


int add_new_value(t_node **head, int value){
	t_node *new_node;

	if (*head == NULL){
		new_node = create_node(value);
		*head = new_node;
	} else 
		if (value < (*head)->value)
			add_new_value(&(*head)->left_next, value);
		else
			add_new_value(&(*head)->right_next, value);

	return 0;	
}

int print_ordered_binary_tree(t_node *head){
	if (head){
		print_ordered_binary_tree(head->left_next);
		printf("- %d ", head->value);
		print_ordered_binary_tree(head->right_next);
	}

	return 0;
	
}

int print_preorder_binary_tree(t_node *head){
        if (head){
		printf("- %d ", head->value);
                print_ordered_binary_tree(head->left_next);
                print_ordered_binary_tree(head->right_next);
        }

        return 0;

}

int print_postorder_binary_tree(t_node *head){
        if (head){
                print_postorder_binary_tree(head->left_next);
                print_postorder_binary_tree(head->right_next);
		printf("- %d ", head->value);
        }

        return 0;

}

int main (){
	t_node **head;
	int option;

	head = (t_node **) malloc (sizeof (t_node));

	system("clear");

	while (1){
		printf("[1] Insert a value.\n");
		printf("[2] Print ordered binary tree.\n");
		printf("[3] Print pre-order binary tree.\n");
		printf("[4] Print post-order binary tree.\n");
		printf("[6] Quit.\n");
		printf("Choose an option.");
		scanf("%d", &option);

		switch (option){
		case 1:
			printf("Please, insert the value to add.\n");
			scanf("%d", &option);
			add_new_value(&(*head), option);
			break;
		case 2:
			printf("Print ordered binary tree.\n");
			print_ordered_binary_tree(*head);
			printf("\n\n");
			break;
		case 3:
			printf("Print pre-order binary tree.\n");
                        print_preorder_binary_tree(*head);
                        printf("\n\n");
                        break;
		case 4:
			printf("Print post-order binary tree.\n");
                        print_postorder_binary_tree(*head);
                        printf("\n\n");
                        break;
		case 6:

		default:
			printf("Quit the program.\n");
			return 0;
		}

	}

	return 0;
}
