TEMPLATE=aux

OTHER_FILES += twitter_eventfeed.files

# lipstick event feed subview
twitter_eventfeed.path = /usr/share/lipstick/eventfeed/
twitter_eventfeed.files = $$PWD/TwitterPostPage.qml \
                          $$PWD/twitter-update.qml \
                          $$PWD/twitter-delegate.qml \
                          $$PWD/TwitterFeedItem.qml \
                          $$PWD/twitter-feed.qml

# translations
TWITTER_TS_FILE = $$OUT_PWD/lipstick-jolla-home-twitter.ts
TWITTER_EE_QM = $$OUT_PWD/lipstick-jolla-home-twitter_eng_en.qm
twitter_ts.commands += lupdate $$PWD -ts $$TWITTER_TS_FILE
twitter_ts.CONFIG += no_check_exist
twitter_ts.output = $$TWITTER_TS_FILE
twitter_ts.input = $$PWD
twitter_ts_install.files = $$TWITTER_TS_FILE
twitter_ts_install.path = /usr/share/translations/source
twitter_ts_install.CONFIG += no_check_exist

# should add -markuntranslated "-" when proper translations are in place (or for testing)
twitter_engineering_english.commands += lrelease -idbased $$TWITTER_TS_FILE -qm $$TWITTER_EE_QM
twitter_engineering_english.CONFIG += no_check_exist
twitter_engineering_english.depends = twitter_ts
twitter_engineering_english.input = $$TWITTER_TS_FILE
twitter_engineering_english.output = $$TWITTER_EE_QM
twitter_engineering_english_install.path = /usr/share/translations
twitter_engineering_english_install.files = $$TWITTER_EE_QM
twitter_engineering_english_install.CONFIG += no_check_exist

QMAKE_EXTRA_TARGETS += twitter_ts twitter_engineering_english
PRE_TARGETDEPS += twitter_ts twitter_engineering_english

INSTALLS += twitter_eventfeed twitter_ts_install twitter_engineering_english_install