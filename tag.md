tag

���ǿ��Դ���һ��tag��ָ����������е�һ���ؼ�ʱ�ڣ�����汾�Ÿ��µ�ʱ����Խ�һ����v2.0������v3.1��֮��ı�ǩ���������Ժ�ع˵�ʱ���ȽϷ��㡣tag��ʹ�úܼ򵥣���Ҫ�����У��鿴tag������tag����֤tag�Լ�����tag��

1�鿴tag

�г�����tag��

git tag

�����г���tag�ǰ���ĸ����ģ��ʹ���ʱ��û��ϵ�����ֻ����鿴ĳЩtag�Ļ������Լ��޶���

git tag -l v1.*

������ֻ���г�1.���İ汾��

2����tag

����������tag��

git tag v1.0

����������tagû�и���������Ϣ����֮��Ӧ���Ǵ���Ϣ��tag��

git tag -a v1.0-m 'first version'

-m������ľ���ע����Ϣ���������պ�鿴��ʱ�������ã���������ͨtag������һ����ǩ����tag��

git tag -s v1.0-m 'first version'

ǰ��������GPG˽Կ���������a����s�����ˡ����˿���Ϊ��ǰ�Ľ������tag�����ǻ�����Ϊ��ǰ��commit���tag��

#���Ȳ鿴��ǰ��commit
git log --oneline
#����������һ��commit��8a5cbc2 updated readme
#����Ϊ�����tag
git tag -a v1.18a5cbc2
3ɾ��tag

�ܼ򵥣�֪��tag���ƺ�

git tag -d v1.0

4��֤tag

�������GPG˽Կ�Ļ��Ϳ�����֤tag��

git tag -v v1.0

5����tag

������ִ��git push��ʱ��tag�ǲ����ϴ����������ģ��������ڵ�github������tag��git push����github��ҳ���ǿ�����tag�ģ�Ϊ�˹�����Щtag�������������

git push origin --tags


�� git clone �����ֿ⣬Ȼ�� git checkout tag_name �Ϳ���ȡ�� tag ��Ӧ�Ĵ����ˡ�
������ʱ�� git ���ܻ���ʾ�㵱ǰ����һ����detached HEAD" ״̬����Ϊ tag �൱����һ�����գ��ǲ��ܸ������Ĵ���ģ����Ҫ�� tag ����Ļ��������޸ģ�����Ҫһ����֧��
git checkout -b branch_name tag_name
������� tag ����һ����֧��Ȼ��ͺ���ͨ�� git ����һ���ˡ�

ɾ��Զ��tag
git push origin --delete tag <tagname>
