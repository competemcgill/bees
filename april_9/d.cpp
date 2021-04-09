#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

#define mp make_pair
#define st first
#define nd second
#define ll long long
#define pll pair<long long, long long>
#define pb push_back

int n, e;
int song_id_count = 0;
int villager_ids[105];

unordered_set<int> known_songs[105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> e;

    for (int i = 1; i <= e; i++)
    {
        int x;
        cin >> x;
        bool is_bard_present = false;
        for (int j = 1; j <= x; j++)
        {
            cin >> villager_ids[j];
            if (villager_ids[j] == 1)
                is_bard_present = true;
        }

        if (is_bard_present)
        {
            int new_song_id = song_id_count++;
            for (int j = 1; j <= x; j++)
                known_songs[villager_ids[j]].insert(new_song_id);
        }
        else
        {
            unordered_set<int> all_known_songs;
            for (int j = 1; j <= x; j++)
                for (int song_id : known_songs[villager_ids[j]])
                    all_known_songs.insert(song_id);

            for (int j = 1; j <= x; j++)
                for (int song_id : all_known_songs)
                    known_songs[villager_ids[j]].insert(song_id);
        }
    }

    for (int i = 1; i <= n; i++)
        if (known_songs[i].size() == song_id_count)
            cout << i << endl;

    return 0;
}
