#include "utils.h"

/**
 * Implementati o functie de cautare a unui nod in
 * 	functie de valoarea din acesta
 * @note   
 * @param  root: Radacina arborelui
 * @param  data: Valoarea de cautat
 * @retval Nodul cautat, daca nu este gasit se returneaza NULL
 */
BST* findNode(BST* root, int data)
{
    if(root->data == data || root == NULL)
        return root;
    
    if(data > root->data)
        return findNode(root->right, data);
    
return findNode(root->left, data);
}
/**
 * Implementati o functie ce returneaza nodul ce stocheaza
 * 	valoarea maxima din arborele/subarborele primit ca parametru
 * @note   
 * @param  root: - Radacina arborelui/subarborelui
 * @retval - Nodul cu valoarea maxima din arbore/subarbore
 */
BST* findMax(BST* root)
{
    BST* v;

    v=root;
    
    while(v->right != NULL)
        v=v->right;
    
return v;
}

/**
 * Implementati o functie ce returneaza nodul ce stocheaza
 * 	valoarea minima din arborele/subarborele primit ca parametru
 * @note   
 * @param  root: - Radacina arborelui/subarborelui
 * @retval - Nodul cu valoarea minima din arbore/subarbore
 */
BST* findMin(BST* root)
{
    BST* v;

    v=root;
    
    while(v->left != NULL)
        v=v->left;
    
return v;    
}

/**
 * Implementati o functie ce returneaza succesorul in inordine al
 * 	nodului primit ca parametru
 * @note   
 * @param  root: Nodul al carui succesor trebuie gasit
 * @retval Succesorul nodului root
 */
BST* findSuccesor(BST* root)
{
    BST *scc;

    if(root->right != NULL)
        return findMin(root->right);
    
    scc=root->parent;

    while(root==scc->right && scc!=NULL)
        {
            root=scc;
            scc=scc->parent;
        }
    
return scc;	
}

/**
 * Implementati o functie ce returneaza predecesorul in inordine al
 * 	nodului primit ca parametru
 * @note   
 * @param  root: Nodul al carui predecesor trebuie gasit
 * @retval Predecesorul nodului root
 */
BST* findPredecessor(BST* root)
{
    BST *prd;

    if(root->left != NULL)
        return findMax(root->left);
    
    prd=root->parent;

    while(root==prd->left && prd!=NULL)
        {
            root=prd;
            prd=prd->parent;
        }
    
return prd;		
}
