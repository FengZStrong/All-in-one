from flask import Flask
from flask import request
from flask import redirect
from flask.ext.script import Manager

app = Flask(__name__)
manager = Manager(app)

@app.route('/')
def index():
    user_agent = request.headers.get('User-Agent')
    return '<p>Your browser is %s.</p>' % user_agent

@app.route('/fengz')
def redirect_fengz():
    return redirect('http://fengz.me/')

@app.route('/user/<name>')
def user(name):
    return '<h1>Hello %s!</h1>' % name

if __name__ == '__main__':
    #manager.run(host = '0.0.0.0', port = 8021, debug = True)
    manager.run()
