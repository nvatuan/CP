import gspread
from oauth2client.service_account import ServiceAccountCredentials
import pprint

scope = ['https://spreadsheets.google.com/feeds',
        'https://www.googleapis.com/auth/drive']
creds = ServiceAccountCredentials.from_json_keyfile_name('editor-secret.json', scope)
client = gspread.authorize(creds)

sheet = client.open('Kế hoạch, Mục tiêu ICPC 2 năm còn lại - K18 Tuấn, Khoa, Khải').get_worksheet(1)

# -- filling data
import topicSplitter as TS
entries = TS.getContent('topics.txt')

startRow = 8
nameCol = 2
pageCol = 10

import time

def attemptUpdateRow(startRow, atCol, content):
    while True:
        try:
            sheet.update_cell(startRow, atCol, content)
        except:
            print('API Quotas Writing limit exceeded. Resting for 60s..')
            time.sleep(60)
        else:
            break
    
chapterCnt = 0
row = startRow

for section in entries:
    print('Writing chapter #', chapterCnt + 1, '...')
    attemptUpdateRow(row, nameCol, section[0][0])
    attemptUpdateRow(row, pageCol, section[0][1])
    row += 1

    for index in range(1, len(section)):
        attemptUpdateRow(row, nameCol, section[index][0])
        attemptUpdateRow(row, pageCol, section[index][1])
        row += 1
    row += 1
    print('Finished with chapter#', chapterCnt + 1, 'out of', len(entries), 'chapter(s)')
    chapterCnt += 1

# pp = pprint.PrettyPrinter()
# pp.pprint(sheet.row_values(2))
# pp.pprint(sheet.row_values(3))
# pp.pprint(sheet.row_values(4))
