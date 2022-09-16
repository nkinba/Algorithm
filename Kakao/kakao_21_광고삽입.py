def solution(play_time, adv_time, logs):
    answer = ''
    
    play_hms = list(map(int, play_time.split(":")))
    adv_hms = list(map(int, adv_time.split(":")))

    play_sec = play_hms[0] * 3600 + play_hms[1] * 60 + play_hms[2]
    adv_sec = adv_hms[0] * 3600 + adv_hms[1] * 60 + adv_hms[2]

    total_time = [0 for i in range(play_sec)]
    for i in range(0, len(logs)):
        total_time[]

    
    return answer


play_time = "02:03:55"
adv_time = "00:14:15"
logs = ["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"]
result = "01:30:59"

solution(play_time, adv_time, logs)