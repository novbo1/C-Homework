#include <iostream>
#include <cmath>
using namespace std;
//�w�q�`��
const int MOVIE = 6;
const int REVIEWER = 4;
//�w�q�禡
void enterArray(int[], int);                                //��J�}�C
int prediction(const int[REVIEWER][MOVIE], const int[]);    //�P�O����rating�|�̱���user

int main()
{
    //�w�q�ܼ�
    int review[REVIEWER][MOVIE] =
    {
        {3, 1, 5, 2, 1, 5},
        {4, 2, 1, 4, 2, 4},
        {3, 1, 2, 4, 4, 1},
        {5, 1, 4, 2, 4, 2}
    }; 
    int userReview[MOVIE] = { -1, -1, -1, -1, -1, -1 };  //��l��

    //���ܵ�
    cout << "Enter ratings for up to 3 movies you want to rate.\n"
        << "For example, for movie 100, enter its rating followed by a space.\n"
        << "100 5 (to rate movie 100 as 5)\n"
        << "Enter up to 3 movies.\n" << endl;

    enterArray(userReview, MOVIE);
    int closest = prediction(review, userReview);

    cout << "Reviewer " << closest << " has the ratings closest to yours.\n";
    return 0;
}

void enterArray(int review[], int size)
{
    int movie, rating, count = 0;
    while (count < 3 && cin >> movie >> rating)
    {
        //���W�L�d��� �~�|�O��
        if (movie >= 100 && movie <= 105)
        {
            review[movie - 100] = rating;
            count++;
        }
        else
        {
            cout << "Invalid movie number. Please enter a movie number between 100 and 105.\n";
        }
    }
}

int prediction(const int review[REVIEWER][MOVIE], const int userReview[MOVIE])
{
    int closestReviewer = 0;
    double minDistance = DBL_MAX; //���]���̤j��

    //�q�Ĥ@��reviewer�}�l
    for (int i = 0; i < REVIEWER; ++i)
    {
        double distance = 0.0;
        for (int j = 0; j < MOVIE; ++j)
        {
            //���L�S���������Z���q�v
            if (userReview[j] != -1)
            {
                distance += pow(userReview[j] - review[i][j], 2);
            }
        }
        distance = sqrt(distance);

        //�d�ݬO�_�O�{�b�̤p��(�̦����p)
        if (distance < minDistance)
        {
            minDistance = distance;
            closestReviewer = i;
        }
    }
    //�j�ǳ̦����p���H
    return closestReviewer;
}