һ��Զ�ֿ̲���master��dev��֧
1. ��¡����
git clone https://github.com/master-dev.git  
# ���git·������Ч�ģ�ʾ������
2. �鿴���з�֧
git branch --all  
# Ĭ������dev��master��֧�����Իῴ������������֧
# master[��������֧] origin/master[Զ������֧] origin/dev[Զ�̿�����֧]
# �¿�¡�����Ĵ���Ĭ��master��origin/master�ǹ����ģ�Ҳ�������ǵĴ��뱣��ͬ��
# ����origin/dev��֧�ڱ���û���κεĹ��������������޷������￪��
3. �������ع���origin/dev�ķ�֧
git checkout dev origin/dev  
# �������ط�֧dev�����Һ�Զ��origin/dev��֧����������dev��֧�ĳ�ʼ�����Զ�̵�dev��֧����һ��
4. �л���dev��֧���п���
git checkout dev  # ������л���dev��֧��Ȼ����ǳ���Ŀ���
5. Ϊ�˸��õ����⣬��ü����������ġ�

��������Զ�ֿ̲�ֻ��mater��֧
1. ��¡����
git clone https://github.com/master-dev.git  
# ���git·������Ч�ģ�ʾ������
2. �鿴���з�֧
git branch --all  
# Ĭ��ֻ��master��֧�����Իῴ������������֧
# master[��������֧] origin/master[Զ������֧]
# �¿�¡�����Ĵ���Ĭ��master��origin/master�ǹ����ģ�Ҳ�������ǵĴ��뱣��ͬ��
3. ���������µ�dev��֧
git branch dev  # �������ط�֧
git branch  # �鿴��֧
# ���ǻῴ��master��dev������master�ϻ���һ���Ǻ�
# ���ʱ��dev��һ�����ط�֧��Զ�ֿ̲ⲻ֪�����Ĵ���
# ���ط�֧���Բ�ͬ����Զ�ֿ̲⣬���ǿ�����dev������Ȼ��merge��master��ʹ��masterͬ�����룬��ȻҲ����ͬ��
4. ����dev��֧
����dev��ָ֧����ͬ��dev��֧�Ĵ��뵽Զ�̷�����
git push origin dev:dev  # ����Զ�ֿ̲�Ҳ��һ��dev��֧��
5. ��dev��֧��������
git checkout dev  # �л���dev��֧���п���
# ��������֮������������ѡ��
# ��һ����������ܿ�������ˣ����Ժϲ�����֧
git checkout master  # �л�������֧
git merge dev  # ��dev��֧�ĸ��ĺ�master�ϲ�
git push  # �ύ����֧����Զ��
git checkout dev  # �л���devԶ�̷�֧
git push  # �ύdev��֧��Զ��
# �ڶ������������û����ɣ�����ֱ������
git push  # �ύ��devԶ�̷�֧
# ע�⣺�ڷ�֧�л�֮ǰ�����commitȫ���ĸı䣬���������֪���Լ�����ʲô
6. ɾ����֧
git push origin :dev  # ɾ��Զ��dev��֧��Σ������Ŷ
# ����������ɾ�����ط�֧
git checkout master  # �л���master��֧
git branch -d dev  # ɾ������dev��֧