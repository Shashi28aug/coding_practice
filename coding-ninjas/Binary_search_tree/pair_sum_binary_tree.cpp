void merge(int *arr, int s, int e){
    int size = (e-s)+1;
    int temp[size];
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = 0;
    
    while(i <= mid && j <= e){
        if(arr[i] > arr[j]){
            temp[k] = arr[j];
            j++;
            k++;
        }else if(arr[i] < arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        }else{
            temp[k] = arr[i];
            i++;
            k++;
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    
    while(i <= mid){
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j <= e){
        temp[k] = arr[j];
        k++;
        j++;
    }
    
    i = s;
    for(int k = 0; k < size; k++){
        arr[i] = temp[k];
        i++;
    }
}
void mergeSort(int *arr, int s, int e){
    if(s >= e)
        return;
	int mid = (s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, e);
}
void pairSumHelper(BinaryTreeNode<int> *root, int *arr, int *pos){
    if(root == NULL)
        return;
    
    arr[(*pos)] = root->data;
    (*pos)++;
    pairSumHelper(root->left, arr, pos);
    pairSumHelper(root->right, arr, pos);
    
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    if(root == NULL)
        return;
    int *arr = new int[1000000];
    int size = 0;
	pairSumHelper(root, arr, &size);
    mergeSort(arr, 0, size-1);
    
    int i = 0;
    int j = size-1;
    
    while(i < j){
        if(arr[i]+arr[j] == sum){
            cout << arr[i] << ' ' << arr[j] << endl;
            i++;
            j--;
        }else if(arr[i]+arr[j] > sum){
            j--;
        }else{
            i++;
        }
    }
    
    delete []arr;
}