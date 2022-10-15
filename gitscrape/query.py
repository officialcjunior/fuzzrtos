from github import Github
import pygit2
import csv

file_path= "freertos.csv"
uname = ""
pwd = ""
g = Github()

def writer(name,link,org,desc,issuecnt):
    s = csv.writer(f)
    s.writerow([name,link,org,desc,issuecnt])

def clone_repo(repo):
    repoClone = pygit2.clone_repository(repo.clone_url, '/home/pwnsolo/fyp/repos/{}'.format(repo.name))

def rprint(repo):

    url = repo.clone_url
    org = repo.organization
    des = repo.description
    cnt = repo.get_issues().totalCount

    print("#########")
    print("""
    repo = {}
    org = {}
    description = {}
    isssues = {}
    """.format(url,org,des,cnt))
    writer(repo.name,url,org,des,cnt)
    
def usetopic():
    for repo in g.search_repositories("topic:FreeRTOS"):
        rate_limit = g.get_rate_limit()
        if rate_limit.search.remaining == 0:
            print("Warning : Rate limit Exceeded ")
            break
        rprint(repo)
        clone_repo(repo)   

f = open(file_path,"w+")
usetopic()
print(g.get_user())
rate_limit = g.get_rate_limit()
print(rate_limit)