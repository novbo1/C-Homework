#include <iostream>
#include <cmath>
using namespace std;
//定義常數
const int MOVIE = 6;
const int REVIEWER = 4;
//定義函式
void enterArray(int[], int);                                //輸入陣列
int prediction(const int[REVIEWER][MOVIE], const int[]);    //判別哪個rating會最接近user

int main()
{
    //定義變數
    int review[REVIEWER][MOVIE] =
    {
        {3, 1, 5, 2, 1, 5},
        {4, 2, 1, 4, 2, 4},
        {3, 1, 2, 4, 4, 1},
        {5, 1, 4, 2, 4, 2}
    }; 
    int userReview[MOVIE] = { -1, -1, -1, -1, -1, -1 };  //初始化

    //提示詞
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
        //不超過範圍時 才會記錄
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
    double minDistance = DBL_MAX; //假設為最大值

    //從第一個reviewer開始
    for (int i = 0; i < REVIEWER; ++i)
    {
        double distance = 0.0;
        for (int j = 0; j < MOVIE; ++j)
        {
            //跳過沒有紀錄成績的電影
            if (userReview[j] != -1)
            {
                distance += pow(userReview[j] - review[i][j], 2);
            }
        }
        distance = sqrt(distance);

        //查看是否是現在最小的(最有關聯)
        if (distance < minDistance)
        {
            minDistance = distance;
            closestReviewer = i;
        }
    }
    //迴傳最有關聯的人
    return closestReviewer;
}