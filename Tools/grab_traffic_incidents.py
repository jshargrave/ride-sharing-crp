import sched, time
import requests
import json
import datetime

TOM_TOM_URL = "https://api.tomtom.com/traffic/services/4/incidentDetails/s2/37.810620,-122.518459,37.707477,-122.356411/12/-1/json?projection=EPSG4326&originalPosition=true&key=8274p6y8umxn4tey9jrr6tqh"
MIN = 60

def grab_incidents(time, file):
    print("Adding to "+file)

    try:
        r = requests.get(TOM_TOM_URL)
        if(r.status_code == 200):
            with open(file, 'a') as f:
                j = json.loads(r.text)
                date = str(datetime.datetime.now())

                j["timestamp"] = date
                json.dump(j, f, indent=4)

    except requests.exceptions.ConnectionError as e:
        print("Error: requests.exceptions.ConnectionError")
    except Exception as e:
        print("Error: ")
        print(e)

    s.enter(time*MIN, 1, grab_incidents, (time, file, ))


if __name__ == '__main__':
    s = sched.scheduler(time.time, time.sleep)

    intervals = [5, 10, 15]
    filename = "traffic_incidents_"

    for x in intervals:
        incident_file = filename+str(x)+"min_interval.txt"
        s.enter(0, 1, grab_incidents, (x, incident_file, ))
    s.run()
