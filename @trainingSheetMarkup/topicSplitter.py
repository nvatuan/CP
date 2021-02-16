class Section:
    def __init__(self, n, pnum):
        self.name, self.page = n.strip(), pnum
    
    def get(self):
        return [self.name, self.page]

    def __repr__(self):
        return 'Name= \'' + str(self.name) + '\' | Page=' + str(self.page) + '\n'
        

class Chapter:
    def __init__(self, chapname, pageNum):
        self.name = chapname
        self.page = pageNum
        self.sections = []

    def addSection(self, sec):
        self.sections.append(sec)
    
    def __repr__(self):
        return str(self.name) + ' | Page: ' + str(self.page)

def getContent(fileName):
    import re
    import io

    f = io.open(fileName, mode ='r', encoding = 'utf-8' )
    content = []
    newChapter = False

    for x in f:
        if x.strip() == '':
            newChapter = True
        else:
            s = x.strip()
            if newChapter:
                newChapter = False
                
                lastSpaceIndex = s.rfind(' ')
                chapName = s[0:lastSpaceIndex]
                pageNum = s[lastSpaceIndex+1:]

                content.append(Chapter(chapName, int(pageNum)))
            else:
                parts = [seg for seg in re.split('\. +', s) if seg]
                
                try:
                    content[-1].addSection(Section(parts[0], int(parts[1])))
                except:
                    print(parts)
                    break
    
    entries = []
    for chap in content:
        chapterEntries = [[chap.name, str(chap.page)]]
        for sec in chap.sections:
            chapterEntries.append([sec.name, str(sec.page)])
        entries.append(chapterEntries)
    return entries
