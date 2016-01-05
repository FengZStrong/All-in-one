from flask import Flask
from flask import request
from flask import redirect
from flask.ext.script import Manager
from flask import render_template
from flask.ext.bootstrap import Bootstrap
from flask.ext.moment import Moment
from datetime import datetime
from flask.ext.wtf import Form
from wtforms import StringField, SubmitField
from wtforms.validators import Required
from flask import session, url_for
from flask import flash

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret'

manager = Manager(app)
bootstrap = Bootstrap(app)
moment = Moment(app)

class NameForm(Form):
    name = StringField('What is your name?', validators = [Required()])
    submit = SubmitField('Submit')

@app.route('/', methods = ['GET', 'POST'])
def index():
    user_agent = request.headers.get('User-Agent')
    form = NameForm()
    if form.validate_on_submit():
        old_name = session.get('name')
        if old_name is not None and old_name != form.name.data:
            flash('Looks like you have changed your name!')
        #name = form.name.data
        session['name'] = form.name.data
        form.name.data = ''
        return redirect(url_for('index'))
    return render_template('index.html', 
                           current_time = datetime.utcnow(), 
                           user_agent = user_agent, form = form, name = session.get('name'))

@app.route('/fengz')
def redirect_fengz():
    return redirect('http://fengz.me/')

@app.route('/user/<name>')
def user(name):
    return render_template('user.html', name = name)

@app.errorhandler(404)
def page_not_found(e):
    return render_template('404.html'), 404

if __name__ == '__main__':
    #manager.run(host = '0.0.0.0', port = 8021, debug = True)
    manager.run()
