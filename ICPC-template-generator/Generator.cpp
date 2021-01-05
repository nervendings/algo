#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int maxn=1000,maxm=100;
const char *index_name = "/config";
char section[maxm][maxn],temp[maxn];
char section_name[maxn],file_name[maxn];
int name_len,fill_len,count_secn;
FILE* tex_source = NULL;
void get_section(const char *s) {
  name_len=fill_len=0;
  int pos=0;
  while(s[pos]&&s[pos]!='<') ++pos;
  if(s[pos]) ++pos;
  while(s[pos]&&s[pos]!='>') section_name[name_len++]=s[pos++];
  while(s[pos]&&s[pos]!='<') ++pos;
  if(s[pos]) ++pos;
  while(s[pos]&&s[pos]!='>') file_name[fill_len++]=s[pos++];
  section_name[name_len]=file_name[fill_len]=0;
}
void read_dir(){
  FILE* dir=fopen(index_name+1,"r");
  count_secn=0;
  while(fgets(section[count_secn++],maxn,dir)!=NULL);
  fclose(dir);
  while(section[count_secn-1][0]=='\0'&&count_secn>0) --count_secn;
  rep(i,0,count_secn-1) if(section[i][strlen(section[i])-1]!='\0')
    section[i][strlen(section[i])-1]='\0';
}
void put_file(const char *filename){
  FILE *fp=fopen(filename,"r");
  while(fgets(temp,maxn,fp)!=NULL)fprintf(tex_source,temp);
  fclose(fp);
}
signed main() {
  auto start_time=chrono::high_resolution_clock::now();
  tex_source=fopen("ICPC-StdLibrary.tex","w");
  put_file("head.in");read_dir();
  printf("section number:%d\n",count_secn);
  rep(i,0,count_secn-1){
    fprintf(tex_source,"\\section{%s}\n",section[i]);
    memcpy(temp,section[i], sizeof temp);
    strcat(temp,index_name);
    printf("section-%d {%s}:\n",i+1,section[i]);
    FILE* fp=fopen(temp,"r");
    int cnt=0;
    while(fgets(temp,maxn,fp)!=NULL){
      if(temp[0]!='<')break;
      get_section(temp);
      printf("subsection-%d {%s}:",++cnt,file_name);
      fprintf(tex_source,"\\subsection{%s} ",section_name);
      memcpy(temp, section[i], sizeof temp);
      temp[strlen(temp)+1] = 0; temp[strlen(temp)] = '/';
      strcat(temp,file_name);
      fprintf(tex_source,"\\lstinputlisting{%s}\n",temp);
      puts(" Done");
    }
    printf("section-%d {%s}: Done\n",i+1,section[i]);
    fclose(fp);
  }
  put_file("tail.in");fclose(tex_source);
  puts("Well Done");
  auto end_time=chrono::high_resolution_clock::now();
  cout<<"\nrun time: "<<chrono::duration<double,milli>(end_time-start_time).count()<<" ms\n";
  getchar();
}
